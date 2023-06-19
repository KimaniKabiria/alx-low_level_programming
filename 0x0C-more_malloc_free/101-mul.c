#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * get_length - gets the length of a string
 * @str: string to evaluate
 * Return: the length of the string
 */

int get_length(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * is_number - checks if a string contains a non number
 * @str: string to be evaluated
 * Return: 0 if a non-digit is found, 1 otherwise
 */

int is_number(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * handle_error - handle error for main to reduce main function size
 */

void handle_error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: always 0 (Success)
 */

int main(int argc, char *argv[])
{
	char *str1, *str2;
	int len_str1, len_str2, total_len, i, tmp_num, num1, num2, *mul, a = 0;

	str1 = argv[1], str2 = argv[2];
	if (argc != 3 || !is_number(str1) || !is_number(str2))
		handle_error();
	len_str1 = get_length(str1);
	len_str2 = get_length(str2);
	total_len = len_str1 + len_str2 + 1;
	mul = malloc(sizeof(int) * total_len);
	if (!mul)
		return (1);
	for (i = 0; i <= len_str1 + len_str2; i++)
		mul[i] = 0;
	for (len_str1 = len_str1 - 1; len_str1 >= 0; len_str1--)
	{
		num1 = str1[len_str1] - '0';
		tmp_num = 0;
		for (len_str2 = get_length(str2) - 1; len_str2 >= 0; len_str2--)
		{
			num2 = str2[len_str2] - '0';
			tmp_num += mul[len_str1 + len_str2 + 1] + (num1 * num2);
			mul[len_str1 + len_str2 + 1] = tmp_num % 10;
			tmp_num /= 10;
		}
		if (tmp_num > 0)
			mul[len_str1 + len_str2 + 1] += tmp_num;
	}
	for (i = 0; i < total_len - 1; i++)
	{
		if (mul[i])
			a = 1;
		if (a)
			_putchar(mul[i] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(mul);
	return (0);
}

