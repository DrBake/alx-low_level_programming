#include "main.h"

/**
 * print_alphabet_x10 - a function that will print the alphabet 10 times
 *
 */

void print_alphabet_x10(void)
{
	int alpha_line, ch;

	for (alpha_line = 0; alpha_line <= 9; alpha_line++)
	{
		for (ch = 'a'; ch <= 'z'; ch++)
			_putchar(ch);
		_putchar('\n');
	}
}
