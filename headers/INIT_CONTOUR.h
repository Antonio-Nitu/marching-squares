// Nitu Andrei-Antonio
#ifndef CONTOURS_H
#define CONTOURS_H

// Define the size of the contour patterns.
#define SIZE 4
// Define the total number of predefined contour patterns.
#define PATTERNS 16

/**
 * @brief Prints a single 4x4 grayscale contour pattern as a P3 PPM image
 * to standard output.
 * @param contour A 4x4 integer array representing the grayscale values of the pattern.
 */
void write_contour(int contour[SIZE][SIZE]);

/**
 * @brief Fills a provided 4x4 array with a predefined contour pattern
 * based on the given index.
 * @param index The index of the contour pattern to retrieve (0-15).
 * If the index is invalid, the output array is filled with zeros.
 * @param out A 4x4 integer array to be filled with the contour data.
 */
void fill_contour_by_index(int index, int out[SIZE][SIZE]);

/**
 * @brief Prints all 16 predefined contour patterns to standard output,
 * each as a separate PPM image.
 */
void INIT_CONTOUR(void);

#endif // CONTOURS_H
