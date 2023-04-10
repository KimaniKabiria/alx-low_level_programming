#include <stdio.h>

/**
 * main - it will print number of arguments passed to it.
 * @argc: is the numbers  of command line arguments.
 * @argv: the array that contains the command line arguments.
 * Return: 0 - (success)
 */

int main(int argc, char *argv[])
{
	if (argc > 0)
		printf("%d\n", argc - 1);

	return (0);
}

