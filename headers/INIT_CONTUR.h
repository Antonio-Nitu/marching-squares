// Nitu Andrei-Antonio

#ifndef INIT_CONTUR_H
#define INIT_CONTUR_H

// The size of one dimension of a square contour pattern.
#define CONTOUR_SIZE 4
// The total number of predefined contour patterns.
#define NUM_CONTOUR_PATTERNS 16

/**
 * @brief Fills a 2D array with a specific contour pattern.
 *
 * Copies the contour pattern corresponding to the given index into the `out`
 * array. If the index is invalid, the `out` array is filled with zeros.
 *
 * @param index The index of the contour pattern (0-15).
 * @param out A 2D integer array of size [CONTOUR_SIZE][CONTOUR_SIZE]
 * to be filled with the pattern data.
 */
void fill_contour_by_index(int index, int out[CONTOUR_SIZE][CONTOUR_SIZE]);

/**
 * @brief The main function for the "INIT_CONTUR" command.
 *
 * Prints all 16 predefined contour patterns to standard output, one after
 * another, each formatted as a valid P3 PPM image.
 */
void INIT_CONTUR(void);

#endif // INIT_CONTUR_H
