course: main.c manager.o 
	gcc -o course main.c manager.o 
manager.o : manager.c manager.h
	gcc -c -o manager.o manager.c
clean:
	rm *.o 
