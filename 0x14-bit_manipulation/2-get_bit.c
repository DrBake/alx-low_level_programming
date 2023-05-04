/**
 * get_bit - returns the value of a bit at a given index
 * @n: unsigned long int to retrieve the bit from
 * @index: index of the bit (0 to 63)
 * Return: value of the bit (0 or 1) if successful, -1 if index is out of range
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int i;

	if (index >= sizeof(unsigned long int) * 8) /* Check if index is out of range */
		return (-1);

	/* Shift through the bits of n and compare with the given index */
	for (i = 0; i <= sizeof(unsigned long int) * 8 - 1; i++, n >>= 1)
	{
		if (index == i)
			return (n & 1); /* Return the value of the bit at the given index */
	}

	return (-1); /* Return -1 if index is not found */
}

