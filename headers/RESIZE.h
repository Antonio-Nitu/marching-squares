// Nitu Andrei-Antonio

#ifndef RESIZE_H
#define RESIZE_H

// The PIXEL_T.h header is required for the definition of the pixel_t type.
#include "PIXEL_T.h"

/**
 * @brief Resizes an image by a factor of 4x (doubling width and height).
 *
 * This function replaces the image matrix pointed to by `image` with a new,
 * larger matrix. Each pixel from the original image is replicated into a 4x4
 * block in the new image. The original matrix is freed, and the integer
 * pointed to by `dim` is updated to the new dimension.
 *
 * @param image A pointer to a pixel_t matrix pointer (pixel_t ***). On success,
 * this will be updated to point to the new, resized image matrix.
 * @param dim A pointer to the dimension of the square image. This value will
 * be multiplied by 4 upon successful resizing.
 */
void RESIZE(pixel_t ***image, int *dim);

#endif // RESIZE_H
