#include <ctype.h>
#include <string.h>

void reverse(char *s);

int get_line(char *s, int lim)
{
    char c;
    char *len = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;

    if (c == '\n')
        *s++ = c;
    *s = 0;

    return strlen(len);
}

int atoi(char *s)
{
    int n = 0, sign;

    while (isspace(*s))
        s++;

    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;

    while (isdigit(*s))
        n = 10 * n + (*s++ - '0');

    return sign * n;
}

double atof(char *s)
{
    double val = 0.0, power = 1.0;
    int sign;

    while (isspace(*s))
        s++;

    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;

    while (isdigit(*s))
        val = 10.0 * val + (*s++ - '0');

    if (*s == '.')
        s++;

    while (isdigit(*s)) {
        val = 10.0 * val + (*s++ - '0');
        power *= 10.0;
    }

    return val * sign / power;
}

void itoa(int n, char *s)
{
    int sign ;
    char *init = s;

    if ((sign = n) < 0)
        n = -n;

    do {
        *s++ = n % 10 + '0';
    } while (n /= 10);

    if (sign < 0)
        *s++ = '-';
    *s = 0;

    reverse(init);
}

void reverse(char *s)
{
    char c;
    char *rev = s + strlen(s) - 1;

    while (s < rev) {
        c = *s;
        *s++ = *rev;
        *rev-- = c;
    }

}
