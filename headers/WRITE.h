// Nitu Andrei-Antonio

#ifndef WRITE_H
#define WRITE_H

// The PIXEL_T.h header is required for the definition of the pixel_t type.
#include "PIXEL_T.h"

/**
 * @brief Writes an image to standard output in P3 PPM format.
 *
 * This function prints the PPM header ("P3", dimensions, max color value)
 * followed by the pixel data for the entire image.
 *
 * @param image The matrix of pixels to be written.
 * @param size The dimension (width and height) of the square image.
 * @param max_value The maximum color value (typically 255).
 */
void WRITE(pixel_t **image, const int size, const int max_value);

#endif // WRITE_H
