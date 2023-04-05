#include "main.h"

/**
 * matcher - check if substring after wildcard matches s1
 * @s1: string 1
 * @s2: string 2
 * @s_hold: placeholder for position after wildcard
 * Return: 1 is match, 0 is not
 */

int matcher(char *s1, char *s2, char *s_hold)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == '\0' && *s2 != '\0')
		return (0);
	if (*s1 == '\0' && *s2 == '*')
		return (matcher(s1, s2 + 1, s2 + 1));
	if (*s2 == '*')
		return (matcher(s1, s2 + 1, s2 + 1));
	if (*s1 == *s2)
		return (matcher(s1 + 1, s2 + 1, s_hold));
	else
		return (matcher(s1 + 1, s_hold, s_hold));
}

/**
 * wildcmp - compare if two strings matches with wildcars included
 * @s1: string 1
 * @s2: string 2
 * Return: I if match, 0 if not
 */

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	else if (*s2 == '*')
		return (matcher(s1, s2 + 1, s2 + 1));
	else
		return (0);
}

