#include "main.h"

/**
 * factorial - get factorial of given number
 * @n: number
 * Return: if less than 0 return -1 else return factorial
 */

int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0 || n == 1)
		return (n);
	else
		return (n * factorial(n - 1));
}

