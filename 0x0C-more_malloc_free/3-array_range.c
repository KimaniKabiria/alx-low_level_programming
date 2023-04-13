#include <stdlib.h>
#include "main.h"

/**
 * array_range - Creates an array of integers ordered from min to max.
 * @min: The first value of the array.
 * @max: The last value of the array.
 * Return: If min > max or the function fails return NULL return to  a pointer.
 */

int *array_range(int min, int max)
{
	int *new_array, i, array_size;

	if (min > max)
		return (NULL);

	array_size = max - min + 1;

	new_array = malloc(sizeof(int) * array_size);

	if (new_array == NULL)
		return (NULL);

	for (i = 0; i < array_size; i++)
		new_array[i] = min++;

	return (new_array);
}

