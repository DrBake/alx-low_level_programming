
#include <stdio.h>

/*
 * Prints the binary representation of a number.
 *
 * @param n: the number to print in binary
 */
void print_binary(unsigned long int n)
{
    /* find the number of bits in the unsigned long int type */
    int num_bits = sizeof(unsigned long int) * 8;

    /* iterate over the bits of the number from left to right */
    for (int i = num_bits - 1; i >= 0; i--)
    {
        /* check if the current bit is 1 or 0 */
        if ((n >> i) & 1)
            printf("1");
        else
            printf("0");
    }
}
