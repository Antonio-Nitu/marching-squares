// Nitu Andrei-Antonio 315CA
#ifndef GRID_H
#define GRID_H

// The PIXEL_T.h header is required for the definition of the pixel_t type.
#include "PIXEL_T.h"

/**
 * @brief Creates a square integer matrix from a pixel matrix, where each
 * element represents the pixel's average brightness.
 * @param a The input matrix of pixels.
 * @param dim The dimension (width and height) of the square matrix.
 * @return A pointer to the newly allocated brightness matrix, or NULL on failure.
 */
int **make_pixel_matrix(pixel_t **a, const int dim);

/**
 * @brief Builds the coarse binary grid by sampling the source image.
 * @param a The input matrix of pixels.
 * @param dim The dimension of the source image.
 * @return A pointer to the newly allocated grid matrix, or NULL on failure.
 */
int **make_grid_matrix(pixel_t **a, const int dim);

/**
 * @brief The main function for the "GRID" command. It builds the grid matrix
 * from the given image and prints it to standard output.
 * @param a The input matrix of pixels.
 * @param dim The dimension of the image.
 */
void GRID(pixel_t **a, const int dim);

#endif // GRID_H
