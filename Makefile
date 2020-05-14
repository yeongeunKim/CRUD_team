CC = gcc
CFLAGS = -W -Wall
TARGET = course
OBJECTS = main.c manager.c

all : $(TARGET)

$(TARGET) :$(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
clean :
	rm *.o course

