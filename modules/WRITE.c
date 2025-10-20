// Nitu Andrei-Antonio
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "PIXEL_T.h"
#include "GENERAL.h"

// Print a matrix of pixels: each pixel as "R G B" on its own line.
void write_pixel_matrix(pixel_t **image, const int size)
{
	for (int row = 0; row < size; ++row) {
		for (int col = 0; col < size; ++col) {
			printf("%d %d %d\n", image[row][col].r,
								 image[row][col].g,
								 image[row][col].b);
		}
	}
}

// Print PPM header and pixel data (ASCII P3 format).
void write_ppm_image(pixel_t **image, const int size, const int max_value)
{
	printf("P3\n%d %d\n%d\n", size, size, max_value);
	write_pixel_matrix(image, size);
}
