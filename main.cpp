
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

#include <iostream>
#include <string>
#include <time.h>
#include "ds1820.h"

/*The One Wire Data Line is Conected to GPIO4 (P1.7)
 * 
 * http://wiki.laub-home.de/wiki/Raspberry_Pi_Sensoren_auslesen#Anschlie.C3.9Fen_des_Temperatur_Sensors
 */

void get_dat_clock()
{
            struct tm *tmp;
    time_t s;
        s = time(NULL);
        tmp = localtime(&s);
        printf("Uhrzeit: %d:%0d:%d\n",tmp->tm_hour,tmp->tm_min,tmp->tm_sec);
        printf("Datum: %d.%d.%d\n", tmp->tm_mday, tmp->tm_mon+1, tmp->tm_mon+1, tmp->tm_year+1900);
}


int main()
{
    ds1820 ds;
    struct tm *tmp;
    time_t s;
    char pfad_devices[]= "/sys/bus/w1/devices";
    int i,sensor_count;
    

    sensor_count=ds.get_howmanny_sensors(pfad_devices);
        
    printf("Temperatur auslesen\n\n");
    
    printf("Datum \t         Uhrzeit\t");
    for( i=1;i<sensor_count;i++)
    {
      printf("Sensor %d: \t",i);
    }
    printf(" \n");
    
    while(1)
    {
      s = time(NULL);
      tmp = localtime(&s);
      printf("%.2d.%.2d.%d \t %.2d:%.2d:%.2d \t", tmp->tm_mday, tmp->tm_mon+1, tmp->tm_year+1900,tmp->tm_hour,tmp->tm_min,tmp->tm_sec);
    
    

      for( i=1;i<sensor_count;i++)
      {
	printf("%2.3f \t",ds.get_sensor_value(pfad_devices,i));
      }
      printf(" \n");
    }
    
    
    
}





