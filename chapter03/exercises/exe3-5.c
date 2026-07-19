#include <stdio.h>

void reverse(char s[]);

/* Convert the integer `n` into base `b` character
 * representation in the string `s` */

void itob(unsigned n, char s[], int b)
{
    int i = 0, sign;
    char digits[] = "0123456789ABCDEF";

    // Negate the base 10 number to make it positive
    if (b == 10 && (sign = n) < 0)
        n = -n;

    do
        s[i++] = digits[n % b];
    while (n /= b);

    // sign for base 10
    if (b == 10 && sign < 0)
        s[i++] = '-';

    s[i] = 0;

    reverse(s);
}
