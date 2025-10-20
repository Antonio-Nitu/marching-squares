// Nitu Andrei-Antonio
#ifndef WRITE_PPM_H
#define WRITE_PPM_H

#include "PIXEL_T.h" // Assumed to contain the definition for pixel_t

/**
 * @brief Print a matrix of pixels to standard output.
 * * Each pixel is printed as "R G B" on its own line.
 * @param image The 2D array of pixels to print.
 * @param size The width and height of the square image matrix.
 */
void write_pixel_matrix(pixel_t **image, const int size);

/**
 * @brief Writes a complete PPM image in ASCII (P3) format to standard output.
 * * This includes the PPM header and the pixel data.
 * @param image The 2D array of pixels representing the image.
 * @param size The width and height of the square image.
 * @param max_value The maximum color value (e.g., 255).
 */
void write_ppm_image(pixel_t **image, const int size, const int max_value);

#endif // WRITE_PPM_H
