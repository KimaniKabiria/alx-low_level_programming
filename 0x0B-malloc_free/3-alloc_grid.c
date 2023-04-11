#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: columns
 * @height: rows
 * Return: pointer to 2d array
 */

int **alloc_grid(int width, int height)
{
	int **grd;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	grd = malloc(height * sizeof(int *));

	if (grd == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grd[i] = malloc(width * sizeof(int));
		if (grd[i] == NULL)
		{
			for (i = 0; i < height; i++)
				free(grd[i]);

			free(grd);
			return (NULL);
		}

		for (j = 0; j < width; j++)
			grd[i][j] = 0;
	}

	return (grd);
}

