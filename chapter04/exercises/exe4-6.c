/*
 * Add commands for handling variables. Add a variable for the most recently printed
 * value.
 *
 * Operations are:
 * 5 6 * A =
 * 4 C =
 * A C +
 *
 * Special thanks to @fsaadatmand/The-C-Programming-Language from his help from his
 * solved exercises.
 *
 * Variables are uppercase (A,B,C ...) and functions are lowercase (sin, cos, exp).
 *
 * @julkefol
*/

#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <ctype.h>
#include <math.h>       /* for sin, cos, tan, pwo, exp */
#include <string.h>

#define MAXOP 100       /* max size of operand or operator */
#define NUMBER '0'      /* signal that a number was found */
#define MAXVAL  100     /* maximum depth of val stack */
#define BUFSIZE 100
#define MATH_FUNC 'F'   /* signal for math functions */


// globals
int sp = 0;             /* next free stack position */
double val[MAXVAL];
char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buffer */

double vars[26];        /* store data in variables stack from value stack */
char recent_var;        /* store most recenet variable */


// functions defs
int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

double topval(void);
int duplicate_top(void);
void swap(void);
void clear_stack(void);
int math_fn(char []);

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                // printf("%lf\n", atof(s));
                push(atof(s));
                break;
            case MATH_FUNC:
                if (math_fn(s))
                    printf("error: unknown function %s\n", s);
                break;
            case '=':   // assign value to varaible from the value stack
                pop();      // zero value
                vars[recent_var - 'A'] = pop();
                break;

            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            /* modulo operator */
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int) pop() % (int) op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%0.8g\n", pop());
                break;

                // commands //

            case '?':
                // print top element from the stack //
                printf("\t%0.8g\n", topval());
                break;
            case 'd':
                // duplicate the top element //
                if (!duplicate_top())
                    printf("Duplicated\n");
                break;
            case 's':
                // swap the first two element //
                swap();
                break;
            case 'c':
                // clear the entire stack //
                clear_stack();
                break;

            default:
                if (isupper(type))
                    push(vars[type - 'A']);
                else
                    printf("error: unknown command %s\n", s);
                break;
        }
        recent_var = type;
    }

    return 0;
}

/* math_fn: checks if the string inside `s` denotes a math function or not */
/* return 0 on success and 1 on failure */
int math_fn(char s[])
{
    if (!strcmp(s, "sin"))
        push(sin(pop()));
    else if (!strcmp(s, "cos"))
        push(cos(pop()));
    else if (!strcmp(s, "tan"))
        push(tan(pop()));
    else if (!strcmp(s, "pow")) {
        double exponent = pop();
        push(pow(pop(), exponent));
    }
    else if (!strcmp(s, "exp"))
        push(exp(pop()));
    else
        return 1;

    return 0;
}


/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    /* ignore white space char and stop when a non white space one found */
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    i = 0;

    /* pick characters from input for math functions */
    if (isalpha(c)) {
        while (isalpha(s[++i] = c = getch()))
            ;
        s[i] = 0;
        ungetch(c);
        return (strlen(s) == 1) ? s[0] : MATH_FUNC;
    }


    /* handle negative sign for number */
    if (c == '-')
        if (!isdigit(s[++i] = c = getch()) && c != '.') {
            ungetch(c);
            c = s[0];
        }

    if (!isdigit(c) && c != '.')
        return c;                   /* not a number */

    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))   /* keep taking numbers from input */
            ;

    if (c == '.')
        while (isdigit(s[++i] = c = getch()))   /* keep taking the numbers
                                                   after decimal point (.) */
            ;

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}


/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* topval: return top element from the stack without popping it */
double topval(void)
{
    if (sp > 0)
        return val[sp - 1];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}


/* duplicate_top: duplicate the top element from the stack */
int duplicate_top(void)
{
    double current;
    if (sp > 0) {
        current = val[sp - 1];
        push(current);
        return 0;
    } else {
        printf("error: stack empty\n");
        return 1;
    }

}

/* swap: swap the top two elements */
void swap(void)
{
    if (sp > 1) {
        double temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp-2] = temp;
    } else
        printf("error: not enought value to swap\n");
}

/* clear_stack: clears the entire stack */
void clear_stack(void)
{
    sp = 0;
}


int getch(void)     /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
