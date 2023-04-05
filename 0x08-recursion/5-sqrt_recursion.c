#include "main.h"

/**
 * find_root - find square root of n, starting from the smallest possible, 0
 * @n: n
 * @r: is root?
 * Return: natural square root, or -1 if not natural root
 */

int find_root(int n, int r)
{
	if (r * r > n)
		return (-1);

	if (r * r == n)
		return (r);

	return (find_root(n, r + 1));
}

/**
 * _sqrt_recursion - find natural square root of n
 * @n: number
 * Return: natural square root, or -1 if not natural root
 */

int _sqrt_recursion(int n)
{
	if (n < 0) /* is natural? */
		return (-1);

	return (find_root(n, 0));
}
