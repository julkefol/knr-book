# Chapter 3 Takeaways — Control Flow

## 3.1 Statement and Blocks

### Statement vs Expression

An expression is a value, while a statement performs an action. A statement can contain expressions, but not vice versa.

### Expression

It can be a combination of values (`5`), variables, operators (`+`, `-`, `/` etc.), and 
function calls (`f()`) that can produce a single value.

An expression is _printable_, _assignable_, and can be _used in math calculation_.

### Examples:
+ `5` (a value expression that evaluates to integer 5)
+ `x + 3` (evaluates to whatever `x` is plus 3)
+ `f()` (evaluates to whatever value `f()` returns)
+ `x == 10` (evaluates to `1` for true or `0` for false)
+ `5 + x - f()` (combined expression that evaluates to whatever value `x` is and the value `f()` returns)

### Statement

It carries out actions.

### Examples:
+ `int x = 5;` (A declaration statement—allocates memory)
+ `if (x > 3) {...}` (A control flow statement—decides where to go)
+ `while (i < 10) { ... }` (A loop statement—repeats an action)
+ `return x;` (A jump statement—exits a function)

> In C, the semicolon is a _statement terminator_
