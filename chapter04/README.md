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
