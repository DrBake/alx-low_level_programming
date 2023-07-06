/**
 * set_bit - sets the value of a bit to 1 at a given
 *		index in an unsigned long int.
 * @n: pointer to an unsigned long int.
 * @index: index of the bit to be set.
 * Return: 1 if successful, -1 if index is out of range.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int mask; /* Mask to set the desired bit to 1 */

	/* Check if index is out of range (0-63) */
	if (index > 63)
		return (-1);

	/* Create a mask with only the desired bit set to 1 */
	mask = 1 << index;

	/* Use bitwise OR to set the desired bit to 1 */
	*n = (*n | mask);

	return (1);
}

