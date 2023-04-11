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
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			num++;
	}
	return (num);
}

/**
* length_w - Get the length of a word
* @str: Pointer
* Return: The length of the word
*/
int length_w(char *str)
{
	int length = 0;

	while (str[length] != ' ' && str[length] != '\0')
		length++;
	return (length);
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
	int total_w = 0, i, j, k, length = 0;
	char **w;

	if (str == 0 || *str == 0)
		return (NULL);
	total_w = number_w(str);
	if (total_w == 0)
		return (NULL);
	w = malloc((total_w + 1) * sizeof(char *));
	if (w == 0)
		return (NULL);
	for (i = 0, j = 0; *str != '\0' &&  i < total_w; i++)
	{
		while (str[j] == ' ')
			j++;
		length = length_w(&str[j]);
		w[i] = malloc((length + 1) * sizeof(char));
		if (w[i] == 0)
		{
			freer(w, i);
			return (NULL);
		}
		for (k = 0; k < length; k++)
			w[i][k] = str[j++];

		w[i][k] = '\0';
	}
	w[total_w] = NULL;
	return (w);
}

