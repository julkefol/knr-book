#include <string.h>

/* strncp: copies at most n characters of t to s */
char* strn_cpy(char *s, char *t, size_t n)
{
    /* make sure n doesn't exceed t's length */
    if (n > strlen(t))
        return NULL;

    /* copy characters */
    for (int i = 0; i < n; i++)
        *s++ = *t++;

    *s = 0;

    return s;
}

/* add t to the end of s */
char* strn_cat(char *s, char *t, size_t n)
{
    /* make sure n doesn't exceed t's length */
    if (n > strlen(t))
        return s;

    /* advance s to the end */
    s += strlen(s);

    for (int i = 0; i < n; i++)
        *s++ = *t++;

    *s = 0;

    return s;
}

/* strn_cmp: compares n characters of lhs to rhs */
/* returns 0 when lhs == rhs
 *       < 0 when lhs < rhs
 *       > 0 when lhs > rhs */

int strn_cmp(char *lhs, char *rhs, size_t n)
{
    for (int i = 0; i < n, *lhs == *rhs; i++, lhs++, rhs++)
        if (!*lhs)
            return 0;
    return *lhs - *rhs;
}
