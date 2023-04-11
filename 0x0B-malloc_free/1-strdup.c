#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: string to duplicate
 * Return: pointer to duplicated string in allocated memory
 */

char *_strdup(char *str)
{
	char *dup_str;
	int i = 0, length = 0, j = 0;

	if (str == NULL)
		return (NULL);

	while (*(str + i))
		length++, i++;
	length++;

	dup_str = malloc(sizeof(char) * length);

	if (dup_str == NULL)
		return (NULL);

	j = 0;
	while (j < length)
	{
		*(dup_str + j) = *(str + j);
		j++;
	}

	return (dup_str);
}

