#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * number_w - get number of words
 * @str: string
 * Return: number of words
 */

int number_w(char *str)
{
	int i, num = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (*str == ' ')
			str++;
		else
		{
			for (; str[i] != ' ' && str[i] != '\0'; i++)
				str++;
			num++;
		}
	}
	return (num);
}

/**
 * freer - frees everything
 * @str: pointer to free
 * @i: counter
 */

void freer(char **str, int i)
{
	for (; i > 0;)
		free(str[--i]);
	free(str);
}

/**
 * strtow - splits string into words
 * @str: string being passed
 * Return: null if string is empty or null or function fails
 */

char **strtow(char *str)
{
	int total_w = 0, i = 0, j = 0, length = 0;
	char **w, *found_w;

	if (str == 0 || *str == 0)
		return (NULL);
	total_w = number_w(str);
	if (total_w == 0)
		return (NULL);
	w = malloc((total_w + 1) * sizeof(char *));
	if (w == 0)
		return (NULL);
	for (i = 0; *str != '\0' &&  i < total_w; i++)
	{
		if (*str == ' ')
			str++;
		else
		{
			found_w = str;
			for (; *str != ' ' && *str != '\0';)
			{
				length++;
				str++;
			}
			w[i] = malloc((length + 1) * sizeof(char));
			if (w[i] == 0)
			{
				freer(w, i);
				return (NULL);
			}
			while (*found_w != ' ' && *found_w != '\0')
			{
				words[i][j] = *found_w;
				found_w++;
				j++;
			}
			w[i][j] = '\0';
			j = 0;
			length = 0;
			str++;
		}
	}
	return (w);
}

