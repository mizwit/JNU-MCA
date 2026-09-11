/*
1. Implementation of Queue.
2. Implement Stack using two Queues.
*/


#include <stdio.h>
#define MAX 100


// Implementation of Queue
struct Queue
{
    int items[MAX];
    int front;
    int rear;
};


// Enqueue an element into the queue
void enqueue(struct Queue *q, int value)
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


// Dequeue an element from the queue
int dequeue(struct Queue *q)
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


// Display the elements in the queue
void display_queue(struct Queue *q)
{
    if (q->front == -1 || q->front > q->rear)
    {
        printf(">> Queue is empty!\n");
        return;
    }
    printf(">> Queue: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}


// Implementation of Stack using two Queues
// Push an element onto the stack using two queues
void push_using_queues(struct Queue *q1, struct Queue *q2, int value)
{
    if (q1->rear == MAX - 1)
    {
        printf(">> Stack Overflow!\n");
        return;
    }
    enqueue(q1, value);
}


// Pop an element from the stack using two queues
int pop_using_queues(struct Queue *q1, struct Queue *q2)
{
    if (q1->front == -1 || q1->front > q1->rear)
    {
        printf(">> Stack Underflow!\n");
        return -1;
    }
    while (q1->front < q1->rear)
    {
        enqueue(q2, dequeue(q1));
    }
    int value = dequeue(q1);
    while (q2->front != -1 && q2->front <= q2->rear)
    {
        enqueue(q1, dequeue(q2));
    }
    return value;
}


// Display the elements in the stack using two queues
void display_stack_using_queues(struct Queue *q1, struct Queue *q2)
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

    printf("TASK 2: Implementation of Queue\n");
    printf("-------\n");
    struct Queue q;
    q.front = -1;
    q.rear = -1;
    enqueue(&q, 10);
    printf(">> Enqueued 10 into the queue\n");
    enqueue(&q, 20);
    printf(">> Enqueued 20 into the queue\n");
    enqueue(&q, 30);
    printf(">> Enqueued 30 into the queue\n");
    display_queue(&q);
    dequeue(&q);
    printf(">> Dequeued from the queue\n");
    display_queue(&q);
    printf("\n\n");

    printf("TASK 3: Implementation of Stack using Two Queues\n");
    printf("-------\n");
    struct Queue q1, q2;
    q1.front = -1;
    q1.rear = -1;
    q2.front = -1;
    q2.rear = -1;
    push_using_queues(&q1, &q2, 10);
    printf(">> Pushed 10 onto the stack using two queues\n");
    push_using_queues(&q1, &q2, 20);
    printf(">> Pushed 20 onto the stack using two queues\n");
    push_using_queues(&q1, &q2, 30);
    printf(">> Pushed 30 onto the stack using two queues\n");
    display_stack_using_queues(&q1, &q2);
    pop_using_queues(&q1, &q2);
    printf(">> Popped from the stack using two queues\n");
    display_stack_using_queues(&q1, &q2);
    printf("\n\n");
    
    return 0;
}