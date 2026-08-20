/* strccat (pointer version): concatenate t to the end of s; s must be big enough */
void strccat(char *s, char t[])
{
    while (*s)
        s++;
    while (*s++ = *t++)
        ;
}
