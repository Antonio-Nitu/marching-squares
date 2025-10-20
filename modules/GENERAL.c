//Nitu Andrei-Antonio
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "PIXEL_T.h"

//Allocates memory for a pixel_t matrix with dimensions line and col.
pixel_t **alloc_matrix_pixel(const int line, const int col)
{
	pixel_t **a = (pixel_t **)malloc(line * sizeof(pixel_t *));

	if (!a) {
		fprintf(stderr, "Allocation failed\n");
		return NULL;
	}
	for (int i = 0; i < line; i++) {
		a[i] = (pixel_t *)malloc(col * sizeof(pixel_t));
		if (!a[i]) {
			fprintf(stderr, "Allocation failed\n");
			for (int j = i - 1; j >= 0; j--) {
				free(a[j]);
			}
			free(a);
			return NULL;
		}
	}
	return a;
}

//Allocates memory for an int matrix with dimensions line and col.
int  **alloc_matrix_int(const int line, const int col)
{
	int **a = (int **)malloc(line * sizeof(int *));

	if (!a) {
		fprintf(stderr, "Allocation failed\n");
		return NULL;
	}
	for (int i = 0; i < line; i++) {
		a[i] = (int *)malloc(col * sizeof(int));
		if (!a[i]) {
			fprintf(stderr, "Allocation failed\n");
			for (int j = i - 1; j >= 0; j--) {
				free(a[j]);
			}
			free(a);
			return NULL;
		}
	}
	return a;
}

//Frees the memory occupied by a pixel matrix with line number of rows.
void free_matrix_pixel(pixel_t ***a, const int line)
{
	if (!a)
		return;
	for (int i = 0; i < line; i++) {
		free((*a)[i]);
	}
	free(*a);
	*a = NULL;
}

//Frees the memory occupied by an int matrix with line number of rows.
void free_matrix_int(int ***a, const int line)
{
	for (int i = 0; i < line; i++) {
		free((*a)[i]);
	}
	free(*a);
	*a = NULL;
}
