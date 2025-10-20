// Nitu Andrei-Antonio 315CA
// GRID.c - build a coarse "grid" from an image by sampling brightness
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "PIXEL_T.h"
#include "GENERAL.h"

#define SIGMA 200

// Build a square integer matrix containing the brightness of each pixel.
// Brightness is the average of the R, G and B channels.
int **make_pixel_matrix(pixel_t **a, const int dim)
{
	int **pixel_sum = alloc_matrix_int(dim, dim);
	if (!pixel_sum) {
		return NULL;
	}
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			pixel_sum[i][j] = (a[i][j].r + a[i][j].g + a[i][j].b) / 3;
		}
	}
	return pixel_sum;
}

// Compute the grid cell value for position (i,j) using the required algorithm.
// The value is the integer average of the center pixel (if inside bounds)
// and its 4 diagonal neighbors that are inside bounds.
// If the average is greater than SIGMA, return 0; otherwise return 1.
int find_value(int i, int j, int **a, int dim)
{
	int lin[4] = { -1, -1, 1, 1 };
	int col[4] = { -1, 1, 1, -1 };
	int sum = 0, count = 0;

	if (i >= 0 && i < dim && j >= 0 && j < dim) {
		sum += a[i][j];
		count++;
	}

	for (int k = 0; k < 4; k++) {
		int ni = i + lin[k];
		int nj = j + col[k];
		if (ni >= 0 && ni < dim && nj >= 0 && nj < dim) {
			sum += a[ni][nj];
			count++;
		}
	}

	if (count > 0) {
		sum /= count;
	}

	return (sum > SIGMA) ? 0 : 1;
}

// Build the grid matrix in memory and populate its elements.
// The grid samples the source image every 4 pixels in both directions.
// The grid size is the ceiling of dim/4.
int **make_grid_matrix(pixel_t **a, const int dim)
{
	int grid_size = (dim + 3) / 4;
	int **pixel_matrix = make_pixel_matrix(a, dim);
	if (!pixel_matrix) {
		return NULL;
	}

	int **grid_matrix = alloc_matrix_int(grid_size, grid_size);
	if (!grid_matrix) {
		free_matrix_int(&pixel_matrix, dim);
		return NULL;
	}

	for (int i = 0; i < dim; i += 4) {
		for (int j = 0; j < dim; j += 4) {
			grid_matrix[i / 4][j / 4] = find_value(i, j, pixel_matrix, dim);
		}
	}

	free_matrix_int(&pixel_matrix, dim);
	return grid_matrix;
}

// Print a square integer matrix to stdout.
void write_matrix_int(int **a, const int dim)
{
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

// Build and print the grid for a given pixel matrix.
void GRID(pixel_t **a, const int dim)
{
	int grid_size = (dim + 3) / 4;
	int **grid_matrix = make_grid_matrix(a, dim);
	if (!grid_matrix) {
		fprintf(stderr, "Failed to build grid\n");
		return;
	}

	printf("Grid calculated successfully [%d x %d]\n", grid_size, grid_size);
	write_matrix_int(grid_matrix, grid_size);
	free_matrix_int(&grid_matrix, grid_size);
}
