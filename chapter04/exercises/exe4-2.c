#include <ctype.h>

/* Extend `atof` to handle scientific notation */
double atof(char s[])
{
    double val, power;
    int i, sign;

    /* skip white space */
    for (i = 0; isspace(s[i]); i++);

    /* determine the sign */
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    /* the non-fractional part */
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    /* the fractional part */
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    val *= sign / power;

    int exp, expsign = 1;

    /* see if exponent is there */
    if (s[i] == 'E' || s[i] == 'e')
        i++;

    /* determine the exponent sign, default is + */
    if (s[i] == '+' || s[i] == '-') {
        expsign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    /* extract exponent value from string */
    for (exp = 0; isdigit(s[i]); i++)
        exp = 10 * exp + (s[i] - '0');

    /* apply the exp value */
    while (exp-- > 0) {
        if (expsign > 0)
            val *= 10;
        else val /= 10;
    }

    return val;
}
