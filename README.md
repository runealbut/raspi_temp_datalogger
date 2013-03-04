raspi_temp_datalogger
=====================
This is an lite temperature datalogger for the Raspberrypi, it works with the Dalla ds1820 OnWire Sensors.

Hardware
--------------
The One Wire Data Line is Conected to GPIO4 (P1.7).
Data is conected to VCC with an Pullup-Resistor.


Configuration of the OneWire KernelModul
--------------

Aktivate the Modul:
```
   pi@raspi:~$ sudo modprobe w1_gpio
   pi@raspi:~$ sudo modprobe w1_therm
```
Look if the Modul ist already loaded:
```
   pi@raspberrypi ~ $ lsmod
   Module                  Size  Used by
   w1_therm                2705  0 
   w1_gpio                 1283  0 
   wire                   23530  2 w1_gpio,w1_therm
   cn                      4649  1 wire
   snd_bcm2835            19889  0 
   snd_pcm                74834  1 snd_bcm2835
   snd_seq                52536  0 
   snd_timer              19698  2 snd_seq,snd_pcm
   snd_seq_device          6300  1 snd_seq
   snd                    52489  5 snd_seq_device,snd_timer,snd_seq,snd_pcm,snd_bcm2835
   snd_page_alloc          4951  1 snd_pcm
   evdev                   8682  0 
   joydev                  9102  0 
   pi@raspberrypi ~ $ 
``` 
 -> It look that it is loaded right.
 
 Looking for OneWire temperature Sensors:
 ```
   pi@raspberrypi ~ $ ls /sys/bus/w1/devices
   10-0008021dad2e  w1_bus_master1
   pi@raspberrypi ~ $
 ```
 The Directory which starts with  "10-" is the Sensor.
 
 Read One Sensor:
  ```
 pi@raspberrypi ~ $ cat /sys/bus/w1/devices/10-0008021dad2e/w1_slave
 25 00 4b 46 ff ff 05 10 5d : crc=5d YES
 25 00 4b 46 ff ff 05 10 5d t=18437
 pi@raspberrypi ~ $ 
  ```
  
 t=18437 means 18,437 Degree Celsius.
 
 The Log Programm
--------------