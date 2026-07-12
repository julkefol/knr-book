# Chapter 3 Takeaways — Control Flow

## 3.1 Statement and Blocks

### Statement vs Expression

An expression is a value, while a statement performs an action. A statement can
contain expressions, but not vice versa.

### Expression

It can be a combination of values (`5`), variables, operators (`+`, `-`, `/` etc.),
and function calls (`f()`) that can produce a single value.

An expression is _printable_, _assignable_, and can be _used in math calculation_.

### Examples:
+ `5` (a value expression that evaluates to integer 5)
+ `x + 3` (evaluates to whatever `x` is plus 3)
+ `f()` (evaluates to whatever value `f()` returns)
+ `x == 10` (evaluates to `1` for true or `0` for false)
+ `5 + x - f()` (combined expression that evaluates to whatever value `x` is and
                the value `f()` returns)

### Statement

It carries out actions.

### Examples:
+ `int x = 5;` (A declaration statement—allocates memory)
+ `if (x > 3) {...}` (A control flow statement—decides where to go)
+ `while (i < 10) { ... }` (A loop statement—repeats an action)
+ `return x;` (A jump statement—exits a function)

> In C, the semicolon is a _statement terminator_

## 3.2 If-Else

```c
if (n >= 0)
    for (i = 0; i < n; i++)
        if (str[i] > 0) {
            printf("...");
        }
else    /* Wrong */
    printf("error -- n is negative!");
```

From the indentation, it may seem that the `else` is part of the first `if`
statement. But the compiler associates the `else` with the inner `if`. It's a good
idea to use braces when there are nested `if`s.

So, the code should be like this,

```c
if (n >= 0) {
    for (i = 0; i < n; i++)
        if (str[i] > 0) {
            printf("...");
        }
} else
    printf("error -- n is negative!");
```

## 3.4 Switch

Example of _multiple labels for single computation_.

```c
switch (ch) {
    case 'a': case 'e': case 'i': case 'o': case 'u':
    case 'A': case 'E': case 'I': case 'O': case 'U':
        printf("It's vowel.\n");
        break;

    default:
        printf("It's consonant.\n");
        break;
}
```

> The `break` statement causes an immediate exit from the `switch`. Because cases 
serve just as labels, after the code for one case is done, execution falls through to
the next unless you take explicit action to escape. `break` and `return` are the most
common ways to leave a switch.

> Falling through cases is a mixed blessing. On the positive side, it allows several
cases to be attached to a single action ... But it also implies that normally each
case must end with a `break` to prevent falling through to the next. Falling through
from one case to another is not robust, being prone to disintegration when the
program is modified. With the exception of multiple labels for a single computation,
fall-throughs should be used sparingly, and commented.

> As a matter of good form, put a `break` after the last case (the `default` here)
even though it's logically unnecessary. Some day when another case gets added at the
end, this bit of defensive programming will save you. 

## 3.5 Loops—While and For

```c
for (expr1; expr2; expr3)
    statement
```

> `expr1` and `expr3` are assignments or function calls and `expr2` is a relational
expression.

> `atof()` ... conversion for floating point numbers.

> `strtol()` for conversion of strings to long integers;

> ... **Shell sort** for sorting an array of integers. ..., which was invented in 
1959 by D. L. Shell.

### Comma "," operator

> which most often finds use in the `for` statement. A pair of expressions separated by
a comma is _evaluated left to right_, and _the type and value of the result are the
type and value of the right operand_.

> The commas that separate function arguments, variables in declarations, etc., are
**not comma operators**, and **do not guarantee left to right evaluation**.
