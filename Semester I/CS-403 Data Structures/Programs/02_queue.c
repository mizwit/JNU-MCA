/*
1. Implementation of Queue using Array.
2. Implementation of Queue using Linked List.
3. Implement Stack using two Queues.
*/


#include <stdio.h>
#include <stdlib.h>
#define MAX 100


// 1. Implementation of Queue using Array
struct ArrayQueue
{
    int items[MAX];
    int front;
    int rear;
};

void array_enqueue(struct ArrayQueue *q, int value)
{
    if (q->rear == MAX - 1)
    {
        printf(">> Queue Overflow!\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int array_dequeue(struct ArrayQueue *q)
{
    if (q->front == -1 || q->front > q->rear)
    {
        printf(">> Queue Underflow!\n");
        q->front = -1;
        q->rear = -1;
        return -1;
    }
    int value = q->items[q->front];
    q->front++;
    return value;
}

void array_queue_display(struct ArrayQueue *q)
{
    if (q->front == -1 || q->front > q->rear)
    {
        printf(">> Queue is empty!\n");
        return;
    }
    printf(">> Queue (front to rear): ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}


// 2. Implementation of Queue using Linked List
struct Node
{
    int data;
    struct Node *next;
};

struct LLQueue
{
    struct Node *front;
    struct Node *rear;
};

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


// Implementation of Stack using two Queues
void push_using_queues(struct ArrayQueue *q1, struct ArrayQueue *q2, int value)
{
    if (q1->rear == MAX - 1)
    {
        printf(">> Stack Overflow!\n");
        return;
    }
    array_enqueue(q1, value);
}

int pop_using_queues(struct ArrayQueue *q1, struct ArrayQueue *q2)
{
    if (q1->front == -1 || q1->front > q1->rear)
    {
        printf(">> Stack Underflow!\n");
        return -1;
    }
    while (q1->front < q1->rear)
    {
        array_enqueue(q2, array_dequeue(q1));
    }
    int value = array_dequeue(q1);
    while (q2->front != -1 && q2->front <= q2->rear)
    {
        array_enqueue(q1, array_dequeue(q2));
    }
    return value;
}

void display_stack_using_queues(struct ArrayQueue *q1, struct ArrayQueue *q2)
{
    if (q1->front == -1 || q1->front > q1->rear)
    {
        printf(">> Stack is empty!\n");
        return;
    }
    printf(">> Stack using two queues: ");
    for (int i = q1->front; i <= q1->rear; i++)
    {
        printf("%d ", q1->items[i]);
    }
    printf("\n");
}


int main()
{
    printf("\n\n");

    printf("TASK 1: Implementation of Queue using Array\n");
    printf("-------\n");
    struct ArrayQueue aq;
    aq.front = -1;
    aq.rear = -1;
    array_enqueue(&aq, 10);
    printf(">> Enqueued 10 into the queue\n");
    array_enqueue(&aq, 20);
    printf(">> Enqueued 20 into the queue\n");
    array_enqueue(&aq, 30);
    printf(">> Enqueued 30 into the queue\n");
    array_queue_display(&aq);
    array_dequeue(&aq);
    printf(">> Dequeued from the queue\n");
    array_queue_display(&aq);
    printf("\n\n");

    printf("TASK 2: Implementation of Queue using Linked List\n");
    printf("-------\n");
    struct LLQueue lq;
    lq.front = NULL;
    lq.rear = NULL;
    ll_enqueue(&lq, 15);
    printf(">> Enqueued 15 into the queue\n");
    ll_enqueue(&lq, 25);
    printf(">> Enqueued 25 into the queue\n");
    ll_enqueue(&lq, 35);
    printf(">> Enqueued 35 into the queue\n");
    ll_queue_display(&lq);
    ll_dequeue(&lq);
    printf(">> Dequeued from the queue\n");
    ll_queue_display(&lq);
    printf("\n\n");

    printf("TASK 3: Implementation of Stack using Two Queues\n");
    printf("-------\n");
    struct ArrayQueue q1, q2;
    q1.front = -1;
    q1.rear = -1;
    q2.front = -1;
    q2.rear = -1;
    push_using_queues(&q1, &q2, 50);
    printf(">> Pushed 50 onto the stack using two queues\n");
    push_using_queues(&q1, &q2, 75);
    printf(">> Pushed 75 onto the stack using two queues\n");
    push_using_queues(&q1, &q2, 100);
    printf(">> Pushed 100 onto the stack using two queues\n");
    display_stack_using_queues(&q1, &q2);
    pop_using_queues(&q1, &q2);
    printf(">> Popped from the stack using two queues\n");
    display_stack_using_queues(&q1, &q2);
    printf("\n\n");
    
    return 0;
}