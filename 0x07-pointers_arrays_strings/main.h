#ifndef MAIN_H
#define MAIN_H

/**
 * _putchar - puts character to standard output
 */

int _putchar(char c);

/**
 * _memset - fill n bytes of memory with a constant value
 */

char *_memset(char *s, char b, unsigned int n);

/**
 * _memcpy - copy n bytes of memory from source to destination
 */

char *_memcpy(char *dest, char *src, unsigned int n);

/**
 * _strchr - locates a character in a string
 */

char *_strchr(char *s, char c);

/**
 * _strspn - return length of string that matches values consistently
 */

unsigned int _strspn(char *s, char *accept);

/**
 * _strpbrk - return pointer to byte in s that matches a byte in accept
 */

char *_strpbrk(char *s, char *accept);

/**
 * _strstr - locate and return pointer to first occurence of sbstring
 */

char *_strstr(char *haystack, char *needle);

/**
 * print_chessboard - print chessboard given set 2D array
 */

void print_chessboard(char (*a)[8]);

#endif
