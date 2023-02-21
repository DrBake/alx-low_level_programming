#include "main.h"

/**
 * _islower - a fuction that checks if the char is lowercase
 *
 * @c: checks input of the function
 *
 * return: returns 1 if 'c' is lower
 *         otherwise return 0 (success)
 */

int _islower(int c) /*return 1 if 'c' is lower */
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}
