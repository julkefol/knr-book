/*
 * EXPLANATION:
 * Modern systems use two's complement number representation. This means an `int`
 * can hold values from `-(2^bitsize) / 2` to `((2^bitsize) / 2) - 1`. The most
 * significant bit is the sign bit; however, it also contributes to the value of
 * negative numbers, making the negative limit larger than the positive limit by
 * 1. When we negate the most negative number, we obtain a value that is larger
 * than the maximum positive integer value, `((2^bitsize) / 2) - 1`. This causes
 * a signed integer overflow and leads to unexpected results.
 *
 * CODE EXPLANATION:
 * This algorithm stores the original sign, converts positive numbers to negative,
 * extracts digits from the negative representation, and adds a minus sign only if
 * the original number was negative. As a result, it works for every `int`,
 * including `INT_MIN`.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[]);     // compile with reverse.c

void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) > 0) // generate sign
        n = -n;         // make `n` negative

    i = 0;
    do {                           // generate digits in reverse order
        s[i++] = -(n % 10) + '0'; // get next digit
    } while (n /= 10);           // keep the loop alive until its n is  `0`

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
