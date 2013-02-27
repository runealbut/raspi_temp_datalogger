/* 
Copyright (C) 2013 runealbut,Tobias Reininghaus  <etwas@runealbut.de>
GPLv3 

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

Dieses Programm ist Freie Software: Sie können es unter den Bedingungen
der GNU General Public License, wie von der Free Software Foundation,
Version 3 der Lizenz oder (nach Ihrer Option) jeder späteren
veröffentlichten Version, weiterverbreiten und/oder modifizieren.

Dieses Programm wird in der Hoffnung, dass es nützlich sein wird, aber
OHNE JEDE GEWÄHRLEISTUNG, bereitgestellt; sogar ohne die implizite
Gewährleistung der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
Siehe die GNU General Public License für weitere Details.

Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
 

 */  

#include "ds1820.h"

string ds1820::pfad_devices = "/sys/bus/w1/devices";


float ds1820::sensor_read(string *sensor_pfad)      
{
  char c;
  float temperatur;
  string puffer, string_temperatur;
  FILE *DS18S20;
 
  //DS18S20 = fopen("/sys/bus/w1/devices/10-0008021dad2e/w1_slave","r");
  DS18S20 = fopen(sensor_pfad,"r");

  if(DS18S20 == NULL) 
  {
    printf("\nFehler beim Versuch den Sensor auszulesen.\n ");
    return EXIT_FAILURE;
  }
  while(fgets(puffer,ZEILENLAENGE, DS18S20))
  {
    int i=0;
    //den zurückgegeben String durch suchen auf die Temperatur
    //for(i=25;i<ZEILENLAENGE;i++)
    do
    {
      i++;
      //printf("i= %d\n",i);
      if(puffer[i]=='t')
      {
	int j;
	int n=i+2;
	for (j=0;j<10;j++)
	{
	  string_temperatur[j]=puffer[n+j];
	}
	break;//printf("temp: %s",string_temperatur);
      }
    }
    while((puffer[i]!='\n')||puffer[i]=='t');
    //printf("ende i= %d\n",i);

  }
  temperatur = atof(string_temperatur)/1000;
//printf("\nTemperatur:%f\n",temperatur);

  fclose(DS18S20);
  return temperatur;
}

int ds1820::open_directory()
{
  if(( dir=opendir(pfad_devices))== NULL)
   {
      printf("Fehler bei opendir ...\n");
      return EXIT_FAILURE;
   }
}

int ds1820::close_directory()
{
   if(closedir(dir) == -1)
   {
      printf("Fehler beim Schließen von %s\n", pfad_devices);
   }
   
   return 0;
}

int ds1820::get_directory_name(string *pfad,int *sensor_number)
{
  int sensor_count=0;// How Many Sensor on the Bus
  string buffer;

      
  while((dirpointer=readdir(dir)) != NULL)
  {
	if((*dirpointer).d_name[2]=='-')
	{
	  //printf("\t %d %s\n",i,(*dirpointer).d_name);
	  //printf("\t\t treffer\n");
	  sensor_count++;
	  if(sensor_count == sensor_number)
	  {
	    sprintf(buffer,"%s/%s/w1_slave",pfad_devices,(*dirpointer).d_name);
	    *pfad=buffer;
	    return 0;
	  }
	  //printf("Temperatursensor %d: %f\n",i,sensor_lesen(buffer));
	  
	}
	

   }
  
  return sensor_count;
}
