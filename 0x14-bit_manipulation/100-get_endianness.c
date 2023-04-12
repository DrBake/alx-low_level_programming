/**
 * get_endianness - a function that checks if
 *                  architecture is little endian
 *                  or big endian
 *
 * Return: 1 if little endian, 0 if big endian
 */
int get_endianness(void)
{
    unsigned int num = 1;
    char *c = (char *)&num;

    /* Check the value of the least significant byte */
    return (int)c[0];
}

