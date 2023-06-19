#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * is_number - iterate through each argv to test if it's a number
 * @test_argv: argument to test
 * Return: true only if entire string is a number, false if not
 */

bool is_number(char *test_argv)
{
	int j = 0;

	for (j = 0; test_argv[j]; j++)
	{
		if (!(test_argv[j] >= '0' && test_argv[j] <= '9'))
			return (0);
	}
	return (1);
}

/**
 * main - print sum if all arguments given are numbers
 * @argc: argument counter
 * @argv: arguments
 * Return: 0 on success, 1 if an argument wasn't a number
 */

int main(int argc, char *argv[])
{
	int i = 1;
	int sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	while (i < argc)
	{
		if (is_number(argv[i]))
			sum += atoi(argv[i]);
		else
		{
			printf("Error\n");
			return (1);
		}
		i++;
	}
	printf("%d\n", sum);

	return (0);
}

