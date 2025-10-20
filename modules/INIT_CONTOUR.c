
// Nitu Andrei-Antonio

// Generates and prints 4x4 contour patterns as PPM (P3) images.

// This file provides 16 predefined 4x4 contour patterns and functions
// to print each pattern as a plain PPM image.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "PIXEL_T.h"
#include "GENERAL.h"

#define SIZE 4
#define PATTERNS 16

// All contour patterns: PATTERNS entries of SIZE x SIZE grayscale values (0-255).
static const unsigned char CONTOURS[PATTERNS][SIZE][SIZE] = {
	// 0
	{
		{0,   0,   0,   0},
		{0,   0,   0,   0},
		{0,   0,   0,   0},
		{0,   0,   0,   0}
	},
	// 1
	{
		{0,   0,   0,   0},
		{0,   0,   0,   0},
		{255, 0,   0,   0},
		{180, 255, 0,   0}
	},
	// 2
	{
		{0,   0,   0,   0},
		{0,   0,   0,   0},
		{0,   0,   0,   255},
		{0,   0,   255, 180}
	},
	// 3
	{
		{0,   0,   0,   0},
		{0,   0,   0,   0},
		{255, 255, 255, 255},
		{180, 180, 180, 180}
	},
	// 4
	{
		{0,   0,   255, 180},
		{0,   0,   0,   255},
		{0,   0,   0,   0},
		{0,   0,   0,   0}
	},
	// 5
	{
		{0,   0,   255, 180},
		{0,   0,   0,   255},
		{255, 0,   0,   0},
		{180, 255, 0,   0}
	},
	// 6
	{
		{0,   0,   255, 180},
		{0,   0,   255, 180},
		{0,   0,   255, 180},
		{0,   0,   255, 180}
	},
	// 7
	{
		{0,   255, 180, 180},
		{255, 180, 180, 180},
		{180, 180, 180, 180},
		{180, 180, 180, 180}
	},
	// 8
	{
		{180, 255, 0,   0},
		{255, 0,   0,   0},
		{0,   0,   0,   0},
		{0,   0,   0,   0}
	},
	// 9
	{
		{180, 255, 0,   0},
		{180, 255, 0,   0},
		{180, 255, 0,   0},
		{180, 255, 0,   0}
	},
	// 10
	{
		{180, 255, 0,   0},
		{255, 0,   0,   0},
		{0,   0,   0,   255},
		{0,   0,   255, 180}
	},
	// 11
	{
		{180, 180, 255, 0},
		{180, 180, 180, 255},
		{180, 180, 180, 180},
		{180, 180, 180, 180}
	},
	// 12
	{
		{180, 180, 180, 180},
		{255, 255, 255, 255},
		{0,   0,   0,   0},
		{0,   0,   0,   0}
	},
	// 13
	{
		{180, 180, 180, 180},
		{180, 180, 180, 180},
		{180, 180, 180, 255},
		{180, 180, 255, 0}
	},
	// 14
	{
		{180, 180, 180, 180},
		{180, 180, 180, 180},
		{255, 180, 180, 180},
		{0,   255, 180, 180}
	},
	// 15
	{
		{255, 255, 255, 255},
		{255, 255, 255, 255},
		{255, 255, 255, 255},
		{255, 255, 255, 255}
	}
};

// Print a single SIZE x SIZE grayscale contour as a P3 PPM image.
// Each value is repeated for R,G,B to create a grayscale image.
void write_contour(int contour[SIZE][SIZE])
{
	printf("P3\n%d %d\n255\n", SIZE, SIZE);
	for (int r = 0; r < SIZE; ++r) {
		for (int c = 0; c < SIZE; ++c) {
			int v = contour[r][c];
			printf("%d %d %d\n", v, v, v);
		}
	}
}

// Fill the provided array with the pattern matching index (0..15).
// If an invalid index is given, the array is zeroed.
void fill_contour_by_index(int index, int out[SIZE][SIZE])
{
	if (index < 0 || index >= PATTERNS) {
		// default to all zeros
		for (int i = 0; i < SIZE; ++i)
			for (int j = 0; j < SIZE; ++j)
				out[i][j] = 0;
		return;
	}

	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			out[i][j] = (int)CONTOURS[index][i][j];
		}
	}
}

// Print all predefined contour patterns one after another as PPM images.
void INIT_CONTOUR(void)
{
	int buf[SIZE][SIZE];
	for (int idx = 0; idx < PATTERNS; ++idx) {
		fill_contour_by_index(idx, buf);
		write_contour(buf);
	}
}