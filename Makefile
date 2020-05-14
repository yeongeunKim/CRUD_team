##course: main.c manager.o 
##	gcc -o course main.c manager.o 
##manager.o : manager.c manager.h
##	gcc -c -o manager.o manager.c
##clean:
##	rm *.o 


CC = gcc
CFLAGS = -W -Wall
TARGET = course
OBJECTS = main.c manager.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
clean :
	rm *.o course

