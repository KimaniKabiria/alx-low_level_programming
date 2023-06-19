#include "main.h"

/**
 * compare_chars - compare start chars and end chars
 * @start: begining of string
 * @end: end of string
 * Return: 1 is palindrome, 0 is not
 */

int compare_chars(char *start, char *end)
{
	if (*start == *end)
		return (compare_chars(start + 1, end - 1));
	else if (*start >= *end)
		return (1);

	return (0);
}

/**
 * get_length - get length of the string
 * @s: char
 * Return: length
 */

int get_length(char *s)
{
	if (*s == '\0')
		return (0);

	s++;
	return (1 + (get_length(s)));
}


/**
 * is_palindrome - check if string is plaindrome
 * @s: string to check
 * Return: 1 is palindrome, 0 is not
 */

int is_palindrome(char *s)
{
	int len = get_length(s);

	return (compare_chars(s, (s + len - 1)));
}

