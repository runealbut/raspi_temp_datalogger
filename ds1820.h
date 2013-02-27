
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
#ifndef DS1820_H_INCLUDED
#define DS1820_H_INCLUDED

#include <sys/types.h>
#include <sys/stat.h>
//#include </usr/include/sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>


#define ZEILENLAENGE 80

    using namespace std;


class ds1820
{
  private:

    struct dirent *dirpointer;
    DIR *dir;
    //static string pfad_device;
    //static char pfad_devices[30];
    //static char pfad_devices[]= "/sys/bus/w1/devices";
    float sensor_read              (char *sensor_pfad);
    int   open_directory           (char *pfad_devices);
    int   close_directory          (char *pfad_devices);
  
  public:
    //static string pfad_device;


    int   get_howmanny_sensors	   (char *pfad_devices);
    float get_sensor_value  (char *pfad_devices,int sensor_number);
  
};



#endif
