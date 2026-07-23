/* strindex: return last occurance of of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;
    int last_occur = -1;

    for (i = 0; s[i] != 0; i++) {
        for (j = i, k = 0; t[k] != 0 && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == 0)
            last_occur = i;
    }

    return last_occur;
}
