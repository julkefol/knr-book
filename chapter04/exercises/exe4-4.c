/*
 * Given the basic framework, it's straightforward to extend to textend the
 * calculator. Add the modulus (%) operator and provisions for negative numbers.
 *
 * @julkefol
*/

#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <ctype.h>

#define MAXOP 100       /* max size of operand or operator */
#define NUMBER '0'      /* signal that a number was found */
#define MAXVAL  100     /* maximum depth of val stack */
#define BUFSIZE 100


// globals
int sp = 0;             /* next free stack position */
double val[MAXVAL];
char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buffer */


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
                printf("error: unknown command %s\n", s);
                break;
        }
    }

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
    /* handlde negative sign for number */
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
