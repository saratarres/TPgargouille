all: ppm

ppm: image_processing.h ppm.out
	gcc -o ppm.out ppm.c