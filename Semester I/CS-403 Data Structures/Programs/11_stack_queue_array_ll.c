/*
Implementation of Stack and Queue using both Array and Linked List:
1. Stack using Array.
2. Stack using Linked List.
3. Queue using Array (circular).
4. Queue using Linked List.
*/


#include <stdio.h>
#include <stdlib.h>
#define MAX 5


// ======================= 1. STACK USING ARRAY =======================
struct ArrayStack
{
    int items[MAX];
    int top;
};

int array_stack_is_empty(struct ArrayStack *s) { return s->top == -1; }
int array_stack_is_full(struct ArrayStack *s) { return s->top == MAX - 1; }

void array_stack_push(struct ArrayStack *s, int value)
{
    if (array_stack_is_full(s))
    {
        printf(">> Stack Overflow!\n");
        return;
    }
    s->items[++s->top] = value;
}

int array_stack_pop(struct ArrayStack *s)
{
    if (array_stack_is_empty(s))
    {
        printf(">> Stack Underflow!\n");
        return -1;
    }
    return s->items[s->top--];
}

int array_stack_peek(struct ArrayStack *s)
{
    if (array_stack_is_empty(s))
    {
        printf(">> Stack is empty!\n");
        return -1;
    }
    return s->items[s->top];
}

void array_stack_display(struct ArrayStack *s)
{
    if (array_stack_is_empty(s))
    {
        printf(">> Stack is empty!\n");
        return;
    }
    printf(">> Stack (bottom to top): ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}


// ===================== 2. STACK USING LINKED LIST =====================
struct Node
{
    int data;
    struct Node *next;
};

int ll_stack_is_empty(struct Node *top) { return top == NULL; }

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

int ll_stack_peek(struct Node *top)
{
    if (top == NULL)
    {
        printf(">> Stack is empty!\n");
        return -1;
    }
    return top->data;
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


// ================= 3. QUEUE USING ARRAY (CIRCULAR) =================
struct ArrayQueue
{
    int items[MAX];
    int front;
    int count;
};

int array_queue_is_empty(struct ArrayQueue *q) { return q->count == 0; }
int array_queue_is_full(struct ArrayQueue *q) { return q->count == MAX; }

void array_enqueue(struct ArrayQueue *q, int value)
{
    if (array_queue_is_full(q))
    {
        printf(">> Queue Overflow!\n");
        return;
    }
    int rear = (q->front + q->count) % MAX;
    q->items[rear] = value;
    q->count++;
}

int array_dequeue(struct ArrayQueue *q)
{
    if (array_queue_is_empty(q))
    {
        printf(">> Queue Underflow!\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return value;
}

int array_queue_peek(struct ArrayQueue *q)
{
    if (array_queue_is_empty(q))
    {
        printf(">> Queue is empty!\n");
        return -1;
    }
    return q->items[q->front];
}

void array_queue_display(struct ArrayQueue *q)
{
    if (array_queue_is_empty(q))
    {
        printf(">> Queue is empty!\n");
        return;
    }
    printf(">> Queue (front to rear): ");
    for (int i = 0; i < q->count; i++)
    {
        printf("%d ", q->items[(q->front + i) % MAX]);
    }
    printf("\n");
}


// =================== 4. QUEUE USING LINKED LIST ===================
struct LLQueue
{
    struct Node *front;
    struct Node *rear;
};

int ll_queue_is_empty(struct LLQueue *q) { return q->front == NULL; }

void ll_enqueue(struct LLQueue *q, int value)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Out of memory\n");
        return;
    }
    new_node->data = value;
    new_node->next = NULL;
    if (q->rear == NULL)
    {
        q->front = new_node;
        q->rear = new_node;
        return;
    }
    q->rear->next = new_node;
    q->rear = new_node;
}

int ll_dequeue(struct LLQueue *q)
{
    if (q->front == NULL)
    {
        printf(">> Queue Underflow!\n");
        return -1;
    }
    struct Node *temp = q->front;
    int value = temp->data;
    q->front = temp->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    return value;
}

int ll_queue_peek(struct LLQueue *q)
{
    if (q->front == NULL)
    {
        printf(">> Queue is empty!\n");
        return -1;
    }
    return q->front->data;
}

void ll_queue_display(struct LLQueue *q)
{
    if (q->front == NULL)
    {
        printf(">> Queue is empty!\n");
        return;
    }
    printf(">> Queue (front to rear): ");
    for (struct Node *node = q->front; node != NULL; node = node->next)
    {
        printf("%d ", node->data);
    }
    printf("\n");
}


int main()
{
    printf("\n\n");

    printf("TASK 1: Stack using Array\n");
    printf("-------\n");
    struct ArrayStack as;
    as.top = -1;
    for (int v = 10; v <= 60; v += 10)
    {
        array_stack_push(&as, v);   // 6th push overflows (MAX = 5)
    }
    array_stack_display(&as);
    printf(">> Peek: %d\n", array_stack_peek(&as));
    printf(">> Popped: %d\n", array_stack_pop(&as));
    array_stack_display(&as);
    printf("\n\n");

    printf("TASK 2: Stack using Linked List\n");
    printf("-------\n");
    struct Node *ls = NULL;
    ll_stack_push(&ls, 10);
    ll_stack_push(&ls, 20);
    ll_stack_push(&ls, 30);
    ll_stack_display(ls);
    printf(">> Peek: %d\n", ll_stack_peek(ls));
    printf(">> Popped: %d\n", ll_stack_pop(&ls));
    ll_stack_display(ls);
    printf("\n\n");

    printf("TASK 3: Queue using Array (circular)\n");
    printf("-------\n");
    struct ArrayQueue aq;
    aq.front = 0;
    aq.count = 0;
    for (int v = 10; v <= 60; v += 10)
    {
        array_enqueue(&aq, v);      // 6th enqueue overflows (MAX = 5)
    }
    array_queue_display(&aq);
    printf(">> Dequeued: %d\n", array_dequeue(&aq));
    printf(">> Dequeued: %d\n", array_dequeue(&aq));
    printf(">> Enqueuing 70 (reuses freed space)...\n");
    array_enqueue(&aq, 70);
    array_queue_display(&aq);
    printf(">> Peek: %d\n", array_queue_peek(&aq));
    printf("\n\n");

    printf("TASK 4: Queue using Linked List\n");
    printf("-------\n");
    struct LLQueue lq;
    lq.front = NULL;
    lq.rear = NULL;
    ll_enqueue(&lq, 10);
    ll_enqueue(&lq, 20);
    ll_enqueue(&lq, 30);
    ll_queue_display(&lq);
    printf(">> Dequeued: %d\n", ll_dequeue(&lq));
    ll_queue_display(&lq);
    printf(">> Peek: %d\n", ll_queue_peek(&lq));
    printf("\n\n");

    return 0;
}
