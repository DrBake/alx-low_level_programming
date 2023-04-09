
#include "main.h"

/*
 * Description - this is a version With Debug Option, this won't work
 *		with the checker copy go to the readme and click
 *		checker version that one will work with the checker.
*/

/**
 * debug_1 - print debug statements
 *
 * @num: value of num
 * @len: length of num
 * @mask: mask of num
 *
 * Return: nothing
*/
void debug_1(unsigned long int num, int len, unsigned long int mask)
{
	printf("Length of %lu (num) is %i ", num, (len + 1));
	printf("and mask (original value 1) ");
	printf("is %lu based ", mask);
	printf("on [length of num - 1] == %i.\n\n", len);
}


/**
 * debug_2 - print debug statements
 *
 * @num: value of num
 * @mask: mask of num
 *
 * Return: nothing
*/
void debug_2(unsigned long int num, unsigned long int mask)
{
	printf("Value of num is %lu, ", num);
	printf("value of mask is %lu and ", mask);
	printf("value of [num & mask] is %lu.\n\n", (num & mask));
}

/**
 * debug_3 - print debug statements
 *
 * @mask: mask of value num
 *
 * Return: nothing
*/
void debug_3(unsigned long int mask)
{
	printf("\nValue of mask is %lu after right shifting by one.\n\n", mask);
}

/**
 * get_length - find the length of @num
 *
 * @num: value to find its length
 *
 * Return: length
*/
int get_length(unsigned long int num)
{
	int len = 0;

	while (num > 0)
	{
		#ifdef DEBUG
		printf("Value of num is %lu before right shifting by one.\n\n", num);
		#endif

		len++;
		num >>= 1; /*shift num to the right by 1*/

		#ifdef DEBUG
		printf("Value of num is %lu after right shifting by one.\n\n", num);
		#endif
	}

	len--;

	return (len);
}

/**
 * print_binary - a function that converts a decimal to binary
 *
 * @num: decimal number to convert
 *
 * Return: nothing
*/
void print_binary(unsigned long int num)
{
	int len;
	unsigned long int mask = 1;

	len = get_length(num);

	if (len > 0) /*create mask based on length of number*/
		mask <<= len; /*shift mask to the left by len*/
	#ifdef DEBUG
	debug_1(num, len, mask);
	#endif

	while (mask > 0)
	{
		#ifdef DEBUG
		debug_2(num, mask);
		#endif

		if (num & mask) /*if num & mask == 1 print 1*/
			_putchar('1');
		else /*else if num & mask == 0 print 0*/
			_putchar('0');

		mask >>= 1; /*shift mask to the right by 1*/

		#ifdef DEBUG
		debug_3(mask);
		#endif
	}
}
