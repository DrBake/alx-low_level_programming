#include <stdlib.h>

/*
 * Convert a binary string to an unsigned int
 *
 * @param b: pointer to a binary string
 * @return: the unsigned int representation of the binary number, or 0 if there
 * is one or more characters in the string b that is not 0 or 1, or b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int i;

	/* check if the input string is NULL */
	if (b == NULL)
		return 0;

	/* iterate through the input string */
	for (i = 0; b[i] != '\0'; i++)
	{
		/* check if the current character is either '0' or '1' */
		if (b[i] != '0' && b[i] != '1')
			return 0;

		/* shift the unsigned int left by one bit (i.e., multiply by 2) */
		num = num << 1;
	
		/* add 1 to the unsigned int if the current character is '1' */
		if (b[i] == '1')
			num = num | 1;
	}

	/* return the unsigned int representation of the binary number */
	return num;
}
