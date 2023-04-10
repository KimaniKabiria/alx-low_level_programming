#include <stdio.h>

/**
 * main - print each argument passed to program on a line
 * @argc: argument counter
 * @argv: pointer to array of arguments
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	int no = 0;
	while (no < argc)
		printf("%s\n", argv[no++]);

	return (0);
}

