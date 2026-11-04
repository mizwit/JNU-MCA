/*
Check whether an infix expression contains balanced parentheses
*/

#include <stdio.h>
#define MAX 100

struct Stack
{
    char items[MAX];
    int top;
};

void push(struct Stack *s, char value)
{
    if (s->top == MAX - 1)
    {
        printf(">> Stack Overflow!\n");
        return;
    }
    s->top++;
    s->items[s->top] = value;
}

char pop(struct Stack *s)
{
    if (s->top == -1)
    {
        printf(">> Stack Underflow!\n");
        return -1;
    }
    char value = s->items[s->top];
    s->top--;
    return value;
}

int is_balanced(char expr[])
{
    struct Stack s;
    s.top = -1;

    for (int i = 0; expr[i] != '\0'; i++)
    {
        if (expr[i] == '(')
        {
            push(&s, expr[i]);
        }
        else if (expr[i] == ')')
        {
            if (s.top == -1)
            {
                return 0;
            }
            pop(&s);
        }
    }

    if (s.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char expr[MAX];
    printf("\nEnter an infix expression: ");
    scanf("%s", expr);

    if (is_balanced(expr))
    {
        printf(">> The expression has balanced parentheses.\n\n");
    }
    else
    {
        printf(">> The expression does NOT have balanced parentheses.\n\n");
    }

    return 0;
}