// Nitu Andrei-Antonio
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "PIXEL_T.h"
#include "GENERAL.h"
#include "READ.h"
#include "WRITE.h"
#include "RESIZE.h"
#include "INIT_CONTUR.h"
#include "GRID.h"
#include "MARCH.h"

static void command_loop(void)
{
	char cmd[16];
	int size = 0;
	int max_val = 0;
	pixel_t **image = NULL;

	while (true) {
		if (scanf("%15s", cmd) != 1) {
			/* End input or error */
			break;
		}

		if (strcmp(cmd, "READ") == 0) {
			free_matrix_pixel(&image, size);
			/* READ returns non-zero on fatal error */
			if (READ(&image, &size, &max_val) != 0)
				break;
		} else if (strcmp(cmd, "WRITE") == 0) {
			WRITE(image, size, max_val);
		} else if (strcmp(cmd, "INIT_CONTUR") == 0) {
			INIT_CONTUR();
		} else if (strcmp(cmd, "GRID") == 0) {
			GRID(image, size);
		} else if (strcmp(cmd, "MARCH") == 0) {
			MARCH(image, size);
		} else if (strcmp(cmd, "RESIZE") == 0) {
			RESIZE(&image, &size);
		} else if (strcmp(cmd, "EXIT") == 0) {
			printf("Program finished.\n");
			break;
		}
	}

	if (image != NULL)
		free_matrix_pixel(&image, size);
}

int main(void)
{
	command_loop();
	return 0;
}