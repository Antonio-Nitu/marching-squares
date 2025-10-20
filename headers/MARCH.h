// Nitu Andrei-Antonio

#ifndef MARCH_H
#define MARCH_H

// The PIXEL_T.h header is required for the definition of the pixel_t type.
#include "PIXEL_T.h"

/**
 * @brief Applies the Marching Squares algorithm to an image.
 *
 * This function calculates a binary grid from the source image, then
 * iterates through the grid to replace 4x4 blocks of the original
 * image with the corresponding contour patterns. The input image is
 * modified in-place.
 *
 * @param image The input/output pixel matrix. It will be overwritten.
 * @param dim The dimension (width and height) of the square image.
 */
void MARCH(pixel_t **image, const int dim);

#endif // MARCH_H
