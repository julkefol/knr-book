void reverse(char s[], int i, int j)
{
    char temp;

    if (i < j-i)
        reverse(s, i+1, j);

    temp = s[i];
    s[i] = s[j - i];
    s[j - i] = temp;
}
