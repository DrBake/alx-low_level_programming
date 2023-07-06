/**
 * clear_bit - sets the value of a bit to 0 at a given index.
 * @n: pointer to an unsigned long int
 * @index: index of the bit to be cleared
 * Return: 1 if successful, -1 if index is out of range
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int m;

	if (index > 63) /* Check if index is valid (0 to 63) */
		return (-1); /* Return -1 if index is out of range */

	m = 1 << index; /* Create a mask with only the desired bit set to 1 */
	if (*n & m) /* Check if the bit is currently set to 1 */
		*n ^= m; /* Use XOR to set the bit to 0 */
	return (1); /* Return 1 to indicate success */
}

