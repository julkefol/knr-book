#include <ctype.h>

int getch(void);
void ungetch(int);

/* getfloat: floating point analog of getint */
int getfloat(double *pn)
{
    double power;
    int c, sign;

    while (isspace(c = getch()))    /* skip white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);      /* it's not a number */
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();

    if (!isdigit(c) && c != '.') {
        ungetch(c);
        return 0;
    }

    /* non-fractional part */
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');

    /* fractional part */
    if (c == '.')
        c = getch();

    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10;
    }

    *pn *= sign / power;

    if (c != EOF)
        ungetch(c);

    return c;
}
