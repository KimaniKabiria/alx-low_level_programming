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
	int c = 0, i = 0, j = 0;
	int length = strlen(str);
	char **w = malloc((length + 1) * sizeof(char *));

	if (str == NULL || *str == '\0')
		return (NULL);

	if (w == NULL)
		return (NULL);

	for (i = 0; i < length && str[i]; i++)
	{
		if (!isspace(str[i]))
		{
			c++;
			j = 1;
			while (j < length && !isspace(str[j]))
				j++;
			w[c - 1] = malloc(j - i + 1);
			if (w[c - 1] == NULL)
			{
				while (--c >= 0)
					free(w[c]);
				free(w);
				return (NULL);
			}
			strncpy(w[c - 1], &str[i], j - i);
			w[c - 1][j - i] = '\0';
			i = j;
		}
	}
	w[c] = NULL;
	return (w);
}

