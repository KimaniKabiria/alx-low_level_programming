#include "main.h"
#define NULL 0

/**
 * _strpbrk - return pointer to byte in s that matches a byte in accept
 * @s: string to search
 * @accept: target matches
 * Return: pointer to index of string at first occurence
 */

char *_strpbrk(char *s, char *accept)
{
	int i = 0;

	while (s[i] != '\0' && s[i] != accept[i])
		i++;

	if (s[i] == accept[i])
		return (&s[i-1]);
	else
		return (NULL);
}

