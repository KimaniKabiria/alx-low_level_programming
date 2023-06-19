#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimum number of coins for an amount of money
 * @argc: should count two arguments
 * @argv: arguments given should be program name and amount of money
 * Return: least number of coins, 0 if negative amount, 1 if amount not given
 */

int main(int argc, char *argv[])
{
	int num = 0;
	int coins = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	if (argv[1][0] == '-')
	{
		printf("0\n");
		return (0);
	}

	num = atoi(argv[1]);

	coins += num / 25;
	num = num % 25;

	coins += num / 10;
	num = num % 10;

	coins += num / 5;
	num = num % 5;

	coins += num / 2;
	num = num % 2;

	coins += num / 1;

	printf("%d\n", coins);
	return (0);
}

