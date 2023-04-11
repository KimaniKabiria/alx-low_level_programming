#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * create_array - create array of chars and initialize with a char
 * @size: size of array
 * @c: fill array values with this char
 * Return: pointer to array
 */

char *create_array(unsigned int size, char c)
{
	char *a; /* Array */
	int i = 0;

	if (size <= 0)
		return (NULL);

	a = malloc(sizeof(char) * size);

	if (a == NULL)
		return (NULL);

	while (i < (int)size)
	{
		*(a + i) = c;
		i++;
	}
	*(a + i) = '\0';

	return (a);
}

