/*
1. Implementation of Stack using Array.
2. Implementation of Stack using Linked List.
3. Reverse a string using Stack.
4. Check whether a string is palindrome using Stack.
*/


#include <stdio.h>
#include <stdlib.h>
#define MAX 100


// 1. Implementation of Stack using Array
struct ArrayStack
{
    int items[MAX];
    int top;
};

void array_stack_push(struct ArrayStack *s, int value)
{
    if (s->top == MAX - 1)
    {
        printf(">> Stack Overflow!\n");
        return;
    }
    s->top++;
    s->items[s->top] = value;
}

int array_stack_pop(struct ArrayStack *s)
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

void array_stack_display(struct ArrayStack *s)
{
    if (s->top == -1)
    {
        printf(">> Stack is empty!\n");
        return;
    }
    printf(">> Stack (top to bottom): ");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}


// 2. Implementation of Stack using Linked List.
struct Node
{
    int data;
    struct Node *next;
};

void ll_stack_push(struct Node **top, int value)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Out of memory\n");
        return;
    }
    new_node->data = value;
    new_node->next = *top;
    *top = new_node;
}

int ll_stack_pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf(">> Stack Underflow!\n");
        return -1;
    }
    struct Node *temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

void ll_stack_display(struct Node *top)
{
    if (top == NULL)
    {
        printf(">> Stack is empty!\n");
        return;
    }
    printf(">> Stack (top to bottom): ");
    for (struct Node *node = top; node != NULL; node = node->next)
    {
        printf("%d ", node->data);
    }
    printf("\n");
}


// 3. Reverse a string using Stack
void reverse_string(char str[])
{
    struct ArrayStack s;
    s.top = -1;
    int i = 0;
    while (str[i] != '\0')
    {
        array_stack_push(&s, str[i]);
        i++;
    }
    i = 0;
    while (s.top != -1)
    {
        str[i] = array_stack_pop(&s);
        i++;
    }
}


// 4. Check whether a string is palindrome using Stack
int is_palindrome(char str[])
{
    struct ArrayStack s;
    s.top = -1;
    int i = 0;
    while (str[i] != '\0')
    {
        array_stack_push(&s, str[i]);
        i++;
    }
    i = 0;
    while (s.top != -1)
    {
        if (str[i] != array_stack_pop(&s))
        {
            printf(">> The string '%s' is NOT a palindrome.\n", str);
            return 0;
        }
        i++;
    }
    printf(">> The string '%s' is a palindrome.\n", str);
    return 1;
}


int main()
{
    printf("\n\n");

    printf("TASK 1: Implementation of Stack using Array\n");
    printf("-------\n");
    struct ArrayStack as;
    as.top = -1;
    array_stack_push(&as, 10);
    printf(">> Pushed 10 onto the stack\n");
    array_stack_push(&as, 20);
    printf(">> Pushed 20 onto the stack\n");
    array_stack_push(&as, 30);
    printf(">> Pushed 30 onto the stack\n");
    array_stack_display(&as);
    array_stack_pop(&as);
    printf(">> Popped from the stack\n");
    array_stack_display(&as);
    printf("\n\n");

    printf("TASK 2: Implementation of Stack using Linked List\n");
    printf("-------\n");
    struct Node *ls = NULL;
    ll_stack_push(&ls, 15);
    printf(">> Pushed 15 onto the stack\n");
    ll_stack_push(&ls, 25);
    printf(">> Pushed 25 onto the stack\n");
    ll_stack_push(&ls, 35);
    printf(">> Pushed 35 onto the stack\n");
    ll_stack_display(ls);
    ll_stack_pop(&ls);
    printf(">> Popped from the stack\n");
    ll_stack_display(ls);
    printf("\n\n");

    printf("TASK 3: Reverse a string using Stack\n");
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