#include "main.h"

/**
 * print_binary - prints the binary representation of an unsigned long int
 * @n: unsigned long int to be converted and printed
 * Return: void
 */

void print_binary(unsigned long int n)
{
	int i;

	if (n == 0)
	{
		_putchar('0'); /* If n is 0, directly print '0' */
		return;
	}

	/* Find position of the most significant set bit */
	for (i = (sizeof(unsigned long int) * 8) - 1; i >= 0; i--)
	{
		if ((n >> i) & 1)
			break;
	}

	/* Print each bit from the most significant to least significant */
	for (; i >= 0; i--)
	{
		_putchar((n >> i) & 1 ? '1' : '0');
	}
}

