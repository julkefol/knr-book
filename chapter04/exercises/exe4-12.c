#define MAXLAN 1001

char s[MAXLAN];

/* recursive version of itoa(int) */
/* used `long` to handle MIN_INT correctly */
int itoa(long n, int i)
{
    /* assign negative sign */
    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }

    /* recursiveness */
    if (n / 10)
        i = itoa(n / 10, i);

    s[i++] = n % 10 + '0';
    s[i] = 0;

    return i;
}
