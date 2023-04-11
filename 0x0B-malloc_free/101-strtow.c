#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "main.h"

/**
 * strtow - splits string to words
 * @str: string
 * Return: pointer to array of strings
 */

char **strtow(char *str)
{
	if (str == NULL || *str == '\0')
		return (NULL);
	int count = 0, i = 0, j = 0, length = strlen(str);

	char **w = malloc((length + 1) * sizeof(char *));

	if (w == NULL)
		return (NULL);

	for (i = 0; i < length && str[i]; i++)
	{
		if (!isspace(str[i]))
		{
			count++;
			j = 1;
			while (j < length && !isspace(str[j]))
				j++;
			w[count - 1] = malloc(j - i + 1);
			if (w[count - 1] == NULL)
			{
				while (--count >= 0)
					free(w[count]);
				free(w);
				return (NULL);
			}
			strncpy(w[count - 1], &str[i], j - i);
			w[count - 1][j - i] = '\0';
			i = j;
		}
	}
	w[count] = NULL;
	return (w);
}

