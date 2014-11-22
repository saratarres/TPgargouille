all: ppm

ppm: ppm.c image_processing.out
	gcc -o ppm.out ppm.c image_processing.out
image_processing: image_processing.out
	gcc -o image_processing.out image_processing.c
