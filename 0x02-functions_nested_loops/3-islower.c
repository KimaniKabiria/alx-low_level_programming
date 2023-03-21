#include "main.h"

/**
 * _isalpha - checks for alphabet character is lowercase
 * @c: character to check
 * Return: 1 if lowercase, 0 if not lowercase
 */

int _islower(int c)
{
    if (c >= 'a' && c <= 'z')
    {
        return(1);
    }
    else
    {
        return(0);
    }
	_putchar('\n');
}