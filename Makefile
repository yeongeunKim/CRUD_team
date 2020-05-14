<<<<<<< HEAD
=======
##course: main.c manager.o 
##	gcc -o course main.c manager.o 
##manager.o : manager.c manager.h
##	gcc -c -o manager.o manager.c
##clean:
##	rm *.o 


>>>>>>> ba86081ab6a10c425d52a8bd2cab4023e257a11f
CC = gcc
CFLAGS = -W -Wall
TARGET = course
OBJECTS = main.c manager.c

all : $(TARGET)

$(TARGET) :$(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
clean :
	rm *.o course

<<<<<<< HEAD
=======

>>>>>>> ba86081ab6a10c425d52a8bd2cab4023e257a11f
