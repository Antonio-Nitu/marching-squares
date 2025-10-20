//Nitu Andrei-Antonio
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "PIXEL_T.h"
#include "GENERAL.h"

//Read a pixel matrix.
//If successful, return 0.
//Otherwise, display error message and return 1.
bool read_matrix(pixel_t **a, const int dim, const int max_val)
{
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (scanf("%d%d%d", &a[i][j].r, &a[i][j].g, &a[i][j].b) != 3) {
				printf("Error: failed to read pixels\n");
				return 1;
			}
			if (a[i][j].r < 0 || a[i][j].r > max_val ||
				a[i][j].g < 0 || a[i][j].g > max_val ||
				a[i][j].b < 0 || a[i][j].b > max_val) {
				printf("Error: invalid pixel value\n");
				return 1;
			}
		}
	}
	return 0;
}

//Read a PPM image.
//If errors occur during reading, display message and return 1.
//If successful, return 0.
int READ(pixel_t ***a, int *dim, int *max_val)
{
	char type[10];

	scanf("%s", type);
	if (!strcmp(type, "P3")) {
		scanf("%d%d%d", dim, dim, max_val);
		*a = alloc_matrix_pixel(*dim, *dim);
		if (read_matrix(*a, *dim, *max_val) == 1) {
			free_matrix_pixel(a, *dim);
			return 1;
		}
		printf("Successfully read image [%d-%d]\n", *dim, *dim);
	} else {
		printf("Error: must be P3\n");
		return 1;
	}
	return 0;
}
