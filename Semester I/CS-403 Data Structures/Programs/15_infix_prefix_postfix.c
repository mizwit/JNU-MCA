/*
1. Convert a Postfix expression to an Infix expression.
2. Convert a Postfix expression to a Prefix expression.
*/

#include <stdio.h>
#include <string.h>
#define MAX 100

struct Stack
{
    char items[MAX][MAX];
    int top;
};

void push(struct Stack *s, char value[])
{
    if (s->top == MAX - 1)
    {
        printf(">> Stack Overflow!\n");
        return;
    }
    s->top++;
    strcpy(s->items[s->top], value);
}

void pop(struct Stack *s, char value[])
{
    if (s->top == -1)
    {
        printf(">> Stack Underflow!\n");
        return;
    }
    strcpy(value, s->items[s->top]);
    s->top--;
}

void postfix_to_infix(char postfix[], char infix[])
{
    struct Stack s;
    s.top = -1;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char symbol = postfix[i];
        if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^')
        {
            char operand1[MAX], operand2[MAX], result[MAX];
            pop(&s, operand2);
            pop(&s, operand1);

            char operator[2] = {symbol, '\0'};
            result[0] = '(';
            result[1] = '\0';
            strcat(result, operand1);
            strcat(result, operator);
            strcat(result, operand2);
            strcat(result, ")");

            push (&s, result);
        }
        else
        {
            char operand[2] = {symbol, '\0'};
            push(&s, operand);
        }
    }
    pop(&s, infix);
}

void postfix_to_prefix(char postfix[], char prefix[])
{
    struct Stack s;
    s.top = -1;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char symbol = postfix[i];
        if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^')
        {
            char operand1[MAX], operand2[MAX], result[MAX];
            pop(&s, operand2);
            pop(&s, operand1);

            result[0] = symbol;
            result[1] = '\0';
            strcat(result, operand1);
            strcat(result, operand2);

            push(&s, result);
        }
        else
        {
            char operand[2] = {symbol, '\0'};
            push(&s, operand);
        }
    }
    pop(&s, prefix);
}

int main()
{
    char postfix[MAX];
    printf("\nEnter the postfix expression: ");
    scanf("%s", postfix);

    char infix[MAX];
    postfix_to_infix(postfix, infix);
    printf(">> Infix expression: %s\n", infix);

    char prefix[MAX];
    postfix_to_prefix(postfix, prefix);
    printf(">> Prefix expression: %s\n\n", prefix);
    
    return 0;
}