# Chapter 4 Takeaways — Functions and Program Structure

## 4.1 Basics of Functions

> (The standard library provides a function `strstr` that is similar to `strindex`,
except that it returns a pointer instead of an index.)

```c
return expression;
```

> The `expression` will be converted to the return type of the function if necessary.

In modern C, there needs to be an expression after `return` otherwise the compiler
should throw an error.

When a function fails to return a value or "falls off the end" of the function by
reaching the closing right brace, its "value" is certain to be garbage.

```c
int foo(void) {}

int main(void)
{
    /* This will print garbage value everytime */
    printf("%d\n", foo());

    return 0;
}
```

## 4.2 Functions Returning Non-integers

Function `atof(s)`, which converts the string `s` to its double-precision floating
point equivalent.

> The function `atof` must be declared and defined consistently. If `atof` itself and
the call to it in `main` have inconsistent types in the same source file, the error
will be detected by the compiler. But if (as is more likely) `atof` were compiled
separately, the mismatch would not be detected, `atof` would return a `double` that
`main` would treat as an `int`, and meaningless answers would result.

With `-c` flag `gcc` generates object file for the source.

```c
/* atoi: convert string s to integer using atof */
int atoi(char s[])
{
    double atof(char s[]);

    return (int) atof(s);
}
```

> The cast states explicitly that the operation is intended, and supresses any
warning.

If casting isn't explicitly specified in the `return` expression, the program will
try to convert the value based on the return type.

__What is `%g`?__

`%g` prints a floating-point value in the shortest sensible form, automatically
choosing between `%f` (fixed-point) and `%e` (scientific notation). Unlike %f, it
removes unnecessary trailing zeros and may omit the decimal point entirely (e.g.,
5.0 → 5). Unlike `%e`, it uses scientific notation only when it makes the output
more compact or readable (e.g., very large or very small numbers). See the result of
the code below.

```c
#include <stdio.h>

int main(void)
{
    printf("%%f with 5.0         -> %f\n", 5.0);
    printf("%%e with 5.0         -> %e\n", 5.0);
    printf("%%g with 5.0         -> %g\n", 5.0);
    printf("%%g with 123456789.0 -> %g\n", 123456789.0);
    printf("%%g with 123.45      -> %g\n", 123.45);

    return 0;
}
```
