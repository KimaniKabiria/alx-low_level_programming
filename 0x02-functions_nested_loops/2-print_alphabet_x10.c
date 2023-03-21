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

    while (count <=10)
    {
    	while (alpha <= 'z')
    	{
    		_putchar(alpha);
    		alpha++;
    	}
    	_putchar('\n');
		count ++;
    }
}
