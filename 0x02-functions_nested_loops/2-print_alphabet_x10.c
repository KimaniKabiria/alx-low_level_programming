#include "main.h"

/**
 * print_alphabet_x10X - prints lowercase alphabet ten times
 * Return: 0
 */

void print_alphabet_x10(void)
{
    int count;
	char alpha;
	
	alpha = 'a';

    for (count = 1; count <=10; count ++)
    {
    	while (alpha <= 'z')
    	{
    		_putchar(alpha);
    		alpha++;
    	}
    	_putchar('\n');
    }
}
