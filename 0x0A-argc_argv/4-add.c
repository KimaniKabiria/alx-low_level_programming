#include <stdio.h>
#include <stdlib.h>

/**
 * main - print sum if all arguments given are numbers
 * @argc: argument counter
 * @argv: arguments
 * Return: 0 on success, 1 if an argument wasn't a number
 */

int main(int argc, char *argv[])
{
	int i = 0;
	int sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	while (i < argc)
	{
		char argvv = *argv[i];

		if (!(argvv >= '0' && argvv <= '9'))
		{
			printf("Error\n");
			return (1);
		}
		else
		{
			sum += atoi(argv[i]);
		}
		i++;
	}
	printf("%d\n", sum);

	return (0);
}

