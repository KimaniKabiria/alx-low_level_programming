#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * str_concat - concatenates two strings
 * @s1: First string
 * @s2: Second string
 * Return: pointer to concatenated string
 */

char *str_concat(char *s1, char *s2)
{
	char *str_con;
	int length1 = 0, length2 = 0, i = 0, j = 0, x = 0, y = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	while (*(s1 + i))
		length1++, i++;

	while (*(s2 + j))
		length2++, j++;

	length2++;

	str_con = malloc(sizeof(char) * (length1 + length2));

	if (str_con == NULL)
		return (NULL);

	while (x < length1)
	{
		*(str_con + x) = *(s1 + x);
		x++;
	}

	while (y < length2)
	{
		*(str_con + x) = *(s2 + y);
		x++, y++;
	}

	return (str_con);
}

