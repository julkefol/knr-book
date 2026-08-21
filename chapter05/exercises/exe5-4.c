#include <string.h>

/* strend: return 1 if the string t occurs at the end of s and 0 otherwise */
int strend(char *s, char *t)
{
    int s_len = strlen(s);
    int t_len = strlen(t);

    if (s_len - t_len > 0)
        s += s_len - t_len;

    if (!strcmp(s, t))
        return 1;

    return 0;
}
