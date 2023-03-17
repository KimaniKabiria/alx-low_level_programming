#include <stdio.h>

/**
 *main - print a num pair from 00-99 but no repeats (00 01, 00 02, 00 03,...)
 *Return: Always 0 (Success)
 */

int main(void)
{
    int i, j;
    for(i = 0; i < 100; i++) {
        for(j = i; j < 100; j++) {
            // Print the first number
            putchar('0' + i / 10);
            putchar('0' + i % 10);
            putchar(' ');
            // Print the second number
            putchar('0' + j / 10);
            putchar('0' + j % 10);
            // Print the comma and space separator
            if(i != 99 || j != 99) {
                putchar(',');
                putchar(' ');
            }
        }
    }
    return (0);
}
