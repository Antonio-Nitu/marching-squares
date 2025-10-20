// Nitu Andrei-Antonio
#ifndef GENERAL_H
#define GENERAL_H

// The PIXEL_T.h header is required for the definition of the pixel_t type.
#include "PIXEL_T.h"

/**
 * @brief Allocates memory for a 2D matrix of pixel_t.
 * @param line The number of rows in the matrix.
 * @param col The number of columns in the matrix.
 * @return A pointer to the allocated matrix, or NULL if allocation fails.
 */
pixel_t **alloc_matrix_pixel(const int line, const int col);

/**
 * @brief Allocates memory for a 2D matrix of integers.
 * @param line The number of rows in the matrix.
 * @param col The number of columns in the matrix.
 * @return A pointer to the allocated matrix, or NULL if allocation fails.
 */
int **alloc_matrix_int(const int line, const int col);

/**
 * @brief Frees the memory occupied by a 2D matrix of pixel_t.
 * @param a A pointer to the matrix to be freed. The pointer will be set to NULL.
 * @param line The number of rows in the matrix.
 */
void free_matrix_pixel(pixel_t ***a, const int line);

/**
 * @brief Frees the memory occupied by a 2D matrix of integers.
 * @param a A pointer to the matrix to be freed. The pointer will be set to NULL.
 * @param line The number of rows in the matrix.
 */
void free_matrix_int(int ***a, const int line);

#endif // GENERAL_H
