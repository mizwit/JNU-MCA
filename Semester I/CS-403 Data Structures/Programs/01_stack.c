/*
1. Implementation of Stack.
2. Reverse a string using Stack.
3. Check whether a string is palindrome using Stack.
*/


#include <stdio.h>
#define MAX 100


// Implementation of Stack
struct Stack
{
    int items[MAX];
    int top;
};


// Push an element onto the stack
void push(struct Stack *s, int value)
{
    if (s->top == MAX - 1)
    {
        printf(">> Stack Overflow!\n");
        return;
    }
    s->top++;
    s->items[s->top] = value;
}


// Pop an element from the stack
int pop(struct Stack *s)
{
    if (s->top == -1)
    {
        printf(">> Stack Underflow!\n");
        return -1;
    }
    int value = s->items[s->top];
    s->top--;
    return value;
}


// Display the elements in the stack
void display_stack(struct Stack *s)
{
    if (s->top == -1)
    {
        printf(">> Stack is empty!\n");
        return;
    }
    printf(">> Stack: ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}


// Reverse a string using Stack
void reverse_string(char str[])
{
    struct Stack s;
    s.top = -1;
    int i = 0;
    while (str[i] != '\0')
    {
        push(&s, str[i]);
        i++;
    }
    i = 0;
    while (s.top != -1)
    {
        str[i] = pop(&s);
        i++;
    }
}


// Check whether a string is palindrome using Stack
int is_palindrome(char str[])
{
    struct Stack s;
    s.top = -1;
    int i = 0;
    while (str[i] != '\0')
    {
        push(&s, str[i]);
        i++;
    }
    i = 0;
    while (s.top != -1)
    {
        if (str[i] != pop(&s))
        {
            printf(">> The string '%s' is NOT a palindrome.\n", str);
            return 0;
        }
        i++;
    }
    printf(">> The string '%s' is a palindrome.\n", str);
    return 1; // Is a palindrome
}


int main()
{
    printf("\n\n");

    printf("TASK 1: Implementation of Stack\n");
    printf("-------\n");
    struct Stack s;
    s.top = -1;
    push(&s, 10);
    printf(">> Pushed 10 onto the stack\n");
    push(&s, 20);
    printf(">> Pushed 20 onto the stack\n");
    push(&s, 30);
    printf(">> Pushed 30 onto the stack\n");
    display_stack(&s);
    pop(&s);
    printf(">> Popped from the stack\n");
    display_stack(&s);
    printf("\n\n");

    printf("TASK 2: Reverse a string using Stack\n");
    printf("-------\n");
    char str[] = "HELLO WORLD";
    printf(">> Original string: %s\n", str);
    reverse_string(str);
    printf(">> Reversed string: %s\n", str);
    printf("\n\n");

    printf("TASK 3: Check whether a string is palindrome using Stack\n");
    printf("-------\n");
    char str1[] = "HELLO";
    is_palindrome(str1);
    char str2[] = "MADAM";
    is_palindrome(str2);
    printf("\n\n");

    return 0;
}