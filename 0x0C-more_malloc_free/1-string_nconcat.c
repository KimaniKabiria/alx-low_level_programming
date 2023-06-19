#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The maximum number of bytes of s2 to concatenate to s1.
 *
 * Return: If the function fails return NULL else return a pointer.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str_con;
	unsigned int len = n, i;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i]; i++)
		len++;

	str_con = malloc(sizeof(char) * (len + 1));

	if (str_con == NULL)
		return (NULL);

	len = 0;

	for (i = 0; s1[i]; i++)
		str_con[len++] = s1[i];

	for (i = 0; s2[i] && i < n; i++)
		str_con[len++] = s2[i];

	str_con[len] = '\0';

	return (str_con);
}

