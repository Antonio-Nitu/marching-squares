// Nitu Andrei-Antonio

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "PIXEL_T.h"
#include "GENERAL.h"
#include "INIT_CONTUR.h"
#include "GRID.h"

// Convert the 2x2 block of the grid into a pattern index (0..15).
// Bits mapping (LSB = 1):
// bit 0 -> grid[row+1][col]
// bit 1 -> grid[row+1][col+1]
// bit 2 -> grid[row][col+1]
// bit 3 -> grid[row][col]
static int compute_pattern_index(int **grid, int row, int col, int grid_dim)
{
	int idx = 0;
	if (row + 1 < grid_dim && col >= 0 && col < grid_dim) {
		idx |= (grid[row + 1][col] & 1) << 0;
	}
	if (row + 1 < grid_dim && col + 1 < grid_dim) {
		idx |= (grid[row + 1][col + 1] & 1) << 1;
	}
	if (row >= 0 && col + 1 < grid_dim) {
		idx |= (grid[row][col + 1] & 1) << 2;
	}
	if (row >= 0 && col >= 0 && col < grid_dim) {
		idx |= (grid[row][col] & 1) << 3;
	}
	return idx;
}

// Choose the appropriate contour matrix for the given pattern index.
static void set_contour_by_index(int index, int contour[4][4])
{
	switch (index) {
	case 0:  contour0(contour);  break;
	case 1:  contour1(contour);  break;
	case 2:  contour2(contour);  break;
	case 3:  contour3(contour);  break;
	case 4:  contour4(contour);  break;
	case 5:  contour5(contour);  break;
	case 6:  contour6(contour);  break;
	case 7:  contour7(contour);  break;
	case 8:  contour8(contour);  break;
	case 9:  contour9(contour);  break;
	case 10: contour10(contour); break;
	case 11: contour11(contour); break;
	case 12: contour12(contour); break;
	case 13: contour13(contour); break;
	case 14: contour14(contour); break;
	default: contour15(contour); break;
	}
}

// Overwrite a 4x4 pixel block in the image with the contour matrix values.
// block_row and block_col are indices in the grid (not pixel coordinates).
static void apply_contour_to_image(int contour[4][4], pixel_t **image, int block_row, int block_col)
{
	int base_row = block_row * 4;
	int base_col = block_col * 4;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			pixel_t *p = &image[base_row + i][base_col + j];
			unsigned char v = (unsigned char) contour[i][j];
			p->r = v;
			p->g = v;
			p->b = v;
		}
	}
}

// Perform the Marching Squares conversion on the image of given dimension.
// The image dimension must be a multiple of 4.
void MARCH(pixel_t **image, const int dim)
{
	int **grid = make_grid_matrix(image, dim);
	if (grid == NULL) {
		fprintf(stderr, "Failed to allocate grid matrix\n");
		return;
	}

	int grid_dim = dim / 4 + 1;
	int contour[4][4];

	for (int r = 0; r < grid_dim - 1; ++r) {
		for (int c = 0; c < grid_dim - 1; ++c) {
			int idx = compute_pattern_index(grid, r, c, grid_dim);
			set_contour_by_index(idx, contour);
			apply_contour_to_image(contour, image, r, c);
		}
	}

	free_matrix_int(&grid, grid_dim);
	printf("Marching Squares applied successfully [%d-%d]\n", dim, dim);
}