//Nitu Andrei-Antonio
/*
 * RESIZE.c
 * Resize an image represented as a matrix of pixels by a factor of 4.
 *
 * This file provides two functions:
 * - pixel_t **make_resized_matrix(pixel_t **src, const int dim)
 *     Allocate and fill a new pixel matrix of size (4*dim x 4*dim) by
 *     replicating each source pixel into a 4x4 block.
 *
 * - void RESIZE(pixel_t ***image, int *dim)
 *     Replace the matrix pointed to by *image with a newly created
 *     resized matrix and update *dim accordingly. Frees the old matrix.
 *
 * Note: alloc_matrix_pixel(rows, cols) and free_matrix_pixel(&matrix, rows)
 * are expected to be provided by GENERAL.h.
 */

#include <stdio.h>
#include <stdlib.h>
#include "PIXEL_T.h"
#include "GENERAL.h"

/* Create a new matrix 4 times larger in each dimension by nearest-neighbor
	replication of the source pixels. Returns NULL on allocation failure. */
pixel_t **make_resized_matrix(pixel_t **src, const int dim)
{
	if (!src || dim <= 0)
		return NULL;

	const int new_dim = dim * 4;
	pixel_t **out = alloc_matrix_pixel(new_dim, new_dim);
	if (!out)
		return NULL;

	for (int r = 0; r < new_dim; ++r) {
		for (int c = 0; c < new_dim; ++c) {
			int sr = r / 4;
			int sc = c / 4;
			out[r][c].r = src[sr][sc].r;
			out[r][c].g = src[sr][sc].g;
			out[r][c].b = src[sr][sc].b;
		}
	}

	return out;
}

/* Replace *image with a resized version (4x area). The original matrix
	is freed. The integer pointed to by dim is updated to the new size. */
void RESIZE(pixel_t ***image, int *dim)
{
	if (!image || !*image || !dim || *dim <= 0)
		return;

	pixel_t **new_mat = make_resized_matrix(*image, *dim);
	if (!new_mat)
		return;

	pixel_t **old = *image;
	*image = new_mat;

	/* free the original matrix using the old dimension */
	free_matrix_pixel(&old, *dim);

	*dim = (*dim) * 4;
	printf("Image successfully resized [%d x %d]\n", *dim, *dim);
}
