// Nitu Andrei-Antonio

#ifndef READ_H
#define READ_H

// The PIXEL_T.h header is required for the definition of the pixel_t type.
#include "PIXEL_T.h"

/**
 * @brief Reads a P3 PPM image from standard input.
 *
 * This function handles reading the PPM header, allocating memory for the
 * pixel matrix, and populating it with pixel data from stdin. It modifies
 * the caller's variables via pointers.
 *
 * @param a A pointer to a pixel_t matrix pointer (pixel_t ***). On success,
 * this will be updated to point to the newly allocated and filled image matrix.
 * @param dim A pointer to an integer that will be filled with the dimension
 * (width and height) of the square image.
 * @param max_val A pointer to an integer that will be filled with the maximum
 * color value specified in the PPM header.
 * @return 0 on success, 1 on failure (e.g., memory allocation error, invalid
 * format, or read error).
 */
int READ(pixel_t ***a, int *dim, int *max_val);

#endif // READ_H
