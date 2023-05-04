/*
 * flip_bits - returns the number of bits flipped in the pattern of the code
 * @n: num one.
 * @m: num two.
 *
 * Return: number of bits flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    unsigned int nbits = 0;

    /* Iterate through each bit in n and m */
    for (; n || m; n >>= 1, m >>= 1)
    {
        /* Check if the least significant bits are different */
        if ((n & 1) != (m & 1))
            nbits++;
    }

    return nbits;
}

