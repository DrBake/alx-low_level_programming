#include "main.h"

/**
 * _islower - a fuction that checks if the char is lowercase
 *
 * return: returns 1 if 'c' is lower 
 */

int _islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}
