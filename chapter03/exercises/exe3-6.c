#include <stdio.h>

void itoa(int, char *, int);
void reverse(char s[]);

void itoa(int n, char s[], int p)
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

    // add padding
    while (p > i)
        s[i++] = ' ';

    s[i] = '\0';
    reverse(s);
}
