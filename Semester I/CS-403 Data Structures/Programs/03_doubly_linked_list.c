/*
1. Implementation of Doubly Linked List.
2. Insertion at the beginning, at a given position, and at the end of a doubly linked list.
3. Deletion at the beginning, at a given position, and at the end of a doubly linked list.
*/


#include <stdio.h>
#include <stdlib.h>


// 1. Implementation of Doubly Linked List
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *create_Node(int data)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void display_list(struct Node *head)
{
    printf(">> NULL <-> ");
    for (struct Node *node = head; node != NULL; node = node->next)
    {
        printf("%d <-> ", node->data);
    }
    printf("NULL\n");
}


// 2. Insertion in Doubly Linked List
void insert_beginning(struct Node **head, int data)
{
    struct Node *new_node = create_Node(data);
    new_node->next = *head;
    if (*head != NULL)
    {
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void insert_middle(struct Node **head, int data, int pos)
{
    if (pos < 1)
    {
        printf(">> Invalid position!\n");
        return;
    }
    if (pos == 1)
    {
        insert_beginning(head, data);
        return;
    }
    struct Node *temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf(">> Invalid position!\n");
        return;
    }
    struct Node *new_node = create_Node(data);
    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
}

void insert_end(struct Node **head, int data)
{
    struct Node *new_node = create_Node(data);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    struct Node *tail = *head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = new_node;
    new_node->prev = tail;
}


// 3. Deletion in Doubly Linked List
void delete_beginning(struct Node **head)
{
    if (*head == NULL)
    {
        printf(">> List is empty!\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }
    free(temp);
}

void delete_middle(struct Node **head, int pos)
{
    if (*head == NULL)
    {
        printf(">> List is empty!\n");
        return;
    }
    if (pos < 1)
    {
        printf(">> Invalid position!\n");
        return;
    }
    if (pos == 1)
    {
        delete_beginning(head);
        return;
    }
    struct Node *target = *head;
    for (int i = 1; i < pos && target != NULL; i++)
    {
        target = target->next;
    }
    if (target == NULL)
    {
        printf(">> Invalid position!\n");
        return;
    }
    target->prev->next = target->next;
    if (target->next != NULL)
    {
        target->next->prev = target->prev;
    }
    free(target);
}

void delete_end(struct Node **head)
{
    if (*head == NULL)
    {
        printf(">> List is empty!\n");
        return;
    }
    struct Node *tail = *head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    if (tail->prev == NULL)
    {
        *head = NULL;
    }
    else
    {
        tail->prev->next = NULL;
    }
    free(tail);
}


int main()
{
    printf("\n\n");

    printf("TASK 1: Implementation of Doubly Linked List\n");
    printf("-------\n");
    struct Node *d = NULL;
    printf(">> Doubly linked list created...");
    printf("\n\n");

    printf("TASK 2: Insertion in Doubly Linked List\n");
    printf("-------\n");
    printf(">> Insert 20 at beginning\n");
    insert_beginning(&d, 20);
    display_list(d);
    printf(">> Insert 40 at end\n");
    insert_end(&d, 40);
    display_list(d);
    printf(">> Insert 10 at beginning\n");
    insert_beginning(&d, 10);
    display_list(d);
    printf(">> Insert 30 at position 3\n");
    insert_middle(&d, 30, 3);
    display_list(d);
    printf("\n\n");

    printf("TASK 3: Deletion in Doubly Linked List\n");
    printf("-------\n");
    printf(">> Delete position 2\n");
    delete_middle(&d, 2);
    display_list(d);
    printf(">> Delete at the beginning\n");
    delete_beginning(&d);
    display_list(d);
    printf(">> Delete at the end\n");
    delete_end(&d);
    display_list(d);
    printf("\n\n");

    return 0;
}