#include <stdio.h>
#include <stdlib.h>

int main()
{
    return 0;
}

#define BITS_PER_CHAR 16
#define MAX_STRING_SIZE 128
#define MAX_BITS (BITS_PER_CHAR * MAX_STRING_SIZE)
#define ulong_t unsigned long

ulong_t hashMap(const char *str, ulong_t x[])
{
    ulong_t h = 0;
    unsigned const char *us;
    int i, shift;
    unsigned char c;

    /* cast s to unsigned const char * */
    /* this ensures that elements of s will be treated as having values >= 0 */
    us = (unsigned const char *) str;

    for (i = 0; *us != 0 && i < MAX_BITS; us++) {
        c = *us;
        for (shift = 0; shift < BITS_PER_CHAR; shift++, i++) {
            // is low bit of c set?
            if (c & 0x1)
                h ^= x[i];
        }

        // shift c to get new bit in lowest position
        c >>= 1;
    }

    return h;
}

