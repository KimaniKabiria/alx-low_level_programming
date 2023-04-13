#include <stdlib.h>
#include <stdio.h>
#include "main.h"

int find_len(char *str);
char *create_xarray(int size);
char *iterate_zeroes(char *str);
void get_prod(char *prod, char *mult, int digit, int zeroes);
void add_nums(char *final_prod, char *next_prod, int next_len);

/**
 * get_length - Gets the length of a string.
 * @str: The string to be measured.
 * Return: The length of the string.
 */

int get_length(char *str)
{
	int len = 0;

	while (*str++)
		len++;

	return (len);
}

/**
 * create_array - Creates an array of chars and initializes it with
 *                 the character 'a'. Adds a terminating null byte.
 * @size: The size of the array to be initialized.
 * Return: A pointer to the array.
 */

char *create_array(int size)
{
	char *array;
	int i;

	array = malloc(sizeof(char) * size);

	if (array == NULL)
		exit(98);

	for (i = 0; i < (size - 1); i++)
		array[i] = 'a';

	array[i] = '\0';

	return (array);
}

/**
 * skip_zeroes - Skips zeros until it hits a non-zero number.
 * @str: The string of numbers to be iterate through.
 * Return: A pointer to the next non-zero element.
 */

char *skip_zeroes(char *str)
{
	while (*str && *str == '0')
		str++;

	return (str);
}

/**
 * get_digit - Converts a digit character to a corresponding int.
 * @c: The character to be converted.
 * Return: The converted int.
 */

int get_digit(char c)
{
	int digit = c - '0';

	if (digit < 0 || digit > 9)
	{
		printf("Error\n");
		exit(98);
	}

	return (digit);
}

/**
 * get_mul - Multiplies a string of numbers by a single digit.
 * @mul: The buffer to store the result.
 * @mult: The string of numbers.
 * @digit: The single digit.
 * @zeroes: The necessary number of leading zeroes.
 */

void get_mul(char *mul, char *mult, int digit, int zeroes)
{
	int mult_len, num, tens = 0;

	mult_len = get_length(mult) - 1;
	mult += mult_len;

	while (*mul)
	{
		*mul = 'a';
		mul++;
	}

	mul--;

	while (zeroes--)
	{
		*mul = '0';
		mul--;
	}

	for (; mult_len >= 0; mult_len--, mult--, mul--)
	{
		if (*mult < '0' || *mult > '9')
		{
			printf("Error\n");
			exit(98);
		}

		num = (*mult - '0') * digit;
		num += tens;
		*mul = (num % 10) + '0';
		tens = num / 10;
	}

	if (tens)
		*mul = (tens % 10) + '0';
}

/**
 * add_nums - Adds the numbers stored in two strings.
 * @final_mul: The buffer storing the running final muluct.
 * @next_mul: The next muluct to be added.
 * @next_len: The length of next_mul.
 */

void add_nums(char *final_mul, char *next_mul, int next_len)
{
	int num, tens = 0;

	while (*(final_mul + 1))
		final_mul++;

	while (*(next_mul + 1))
		next_mul++;

	for (; *final_mul != 'a'; final_mul--)
	{
		num = (*final_mul - '0') + (*next_mul - '0');
		num += tens;
		*final_mul = (num % 10) + '0';
		tens = num / 10;

		next_mul--;
		next_len--;
	}

	for (; next_len >= 0 && *next_mul != 'a'; next_len--)
	{
		num = (*next_mul - '0');
		num += tens;
		*final_mul = (num % 10) + '0';
		tens = num / 10;

		final_mul--;
		next_mul--;
	}

	if (tens)
		*final_mul = (tens % 10) + '0';
}

/**
 * main - Multiplies two positive numbers.
 * @argv: The number of arguments passed to the program.
 * @argc: An array of pointers to the arguments.
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	char *final_mul, *next_mul;
	int size, i, digit, zeroes = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	if (*(argv[1]) == '0')
		argv[1] = skip_zeroes(argv[1]);
	if (*(argv[2]) == '0')
		argv[2] = skip_zeroes(argv[2]);
	if (*(argv[1]) == '\0' || *(argv[2]) == '\0')
	{
		printf("0\n");
		return (0);
	}

	size = get_length(argv[1]) + get_length(argv[2]);
	final_mul = create_array(size + 1);
	next_mul = create_array(size + 1);

	for (i = get_length(argv[2]) - 1; i >= 0; i--)
	{
		digit = get_digit(*(argv[2] + i));
		get_mul(next_mul, argv[1], digit, zeroes++);
		add_nums(final_mul, next_mul, size - 1);
	}
	for (i = 0; final_mul[i]; i++)
	{
		if (final_mul[i] != 'a')
			putchar(final_mul[i]);
	}
	putchar('\n');

	free(next_mul);
	free(final_mul);

	return (0);
}

