#include "main.h"

/**
 * _abs - compute absolute value of integer
 * @nun: integer argument
 * Return: absolute value
 */

int _abs(int num)
{
    if (num < 0)
    {
        return (-num);
    } 
    else
    {
        return (num);
    }
	_putchar('\n');
    return (0);
}