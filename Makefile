VERSION = 0.1 
CC      = g++
CFLAGS  = -Wall 
#LDFLAGS = -l bcm2835 -lm -l rt
LDFLAGS =  -lm -l rt -std=c++11

OBJ= main.o ds1820.o 




prog: $(OBJ)
	$(CC) $(CFLAGS) -o raspi_temp_datalogger   $(OBJ) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 


