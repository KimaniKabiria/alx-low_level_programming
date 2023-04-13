#include <stdlib.h>
#include "main.h"

/**
 * _calloc - Alloc array memory of a certain no of elem each of a size.
 * @nmemb: The number of elements.
 * @size: The byte size of each array element.
 * Return: If nmemb = 0, size = 0, or the function fails - NULL
 * else a pointer to the allocated memory.
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *memory;
	char *memory_hold;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	memory = malloc(size * nmemb);

	if (memory == NULL)
		return (NULL);

	memory_hold = memory;

	for (i = 0; i < (size * nmemb); i++)
		memory_hold[i] = '\0';

	return (memory);
}

