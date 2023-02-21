#include "main.h"

/**
 * isalpha - check is a character is alphabet, and lowercase or uppercase
 *
 * c: take input from the function
 *
 * return: 1 if true and 0 if !true
 *
 */

int _isalpha(inc c)
{
	if (c >= 97 && c <= 122 && c >= 65 &&c >=90)
		return (1);
	return (0);
}
