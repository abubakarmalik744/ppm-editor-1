image: image.o ppm.o scanner.o
	gcc image.o ppm.o scanner.o -o image

image.o: image.c
	gcc -Wall -g -c image.c

ppm.o: ppm.c ppm.h
	gcc -Wall -g -c ppm.c

scanner.o: scanner.c scanner.h
	gcc -Wall -g -c scanner.c

clean:
	rm image.o ppm.o scanner.o

	
