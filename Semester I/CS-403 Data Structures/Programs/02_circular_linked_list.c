/*
1. Implementation of Circular Linked List.
2. Insertion at the beginning, at a given position, and at the end of a circular linked list.
3. Deletion at the beginning, at a given position, and at the end of a circular linked list.
*/


#include <stdio.h>
#include <stdlib.h>


// 1. Implementation of a Circular Linked List
struct Node
{
    int data;
    struct Node *next;
};

struct Node *create_node(int data)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void display_list(struct Node *head)
{
    if (head == NULL)
    {
        printf(">> (empty)\n");
        return;
    }
    printf(">> ");
    struct Node *node = head;
    do
    {
        printf("%d -> ", node->data);
        node = node->next;
    } while (node != head);
    printf("(back to head)\n");
}


// 2. Insertion in Circular Linked List
void insert_beginning(struct Node **head, int data)
{
    struct Node *new_node = create_node(data);
    if (*head == NULL)
    {
        new_node->next = new_node;
        *head = new_node;
        return;
    }
    struct Node *last = *head;
    while (last->next != *head)
    {
        last = last->next;
    }
    new_node->next = *head;
    last->next = new_node;
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
    if (*head == NULL)
    {
        printf(">> Invalid position!\n");
        return;
    }
    struct Node *temp = *head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == *head)
        {
            printf(">> Invalid position!\n");
            return;
        }
    }
    struct Node *new_node = create_node(data);
    new_node->next = temp->next;
    temp->next = new_node;
}

void insert_end(struct Node **head, int data)
{
    struct Node *new_node = create_node(data);
    if (*head == NULL)
    {
        new_node->next = new_node;
        *head = new_node;
        return;
    }
    struct Node *last = *head;
    while (last->next != *head)
    {
        last = last->next;
    }
    last->next = new_node;
    new_node->next = *head;
}


// 3. Deletion in Circular Linked List
void delete_beginning(struct Node **head)
{
    if (*head == NULL)
    {
        printf(">> List is empty!\n");
        return;
    }
    if ((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *last = *head;
    while (last->next != *head)
    {
        last = last->next;
    }
    struct Node *temp = *head;
    last->next = (*head)->next;
    *head = (*head)->next;
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
    struct Node *prev = *head;
    for (int i = 1; i < pos - 1; i++)
    {
        prev = prev->next;
        if (prev == *head)
        {
            printf(">> Invalid position!\n");
            return;
        }
    }
    if (prev->next == *head)
    {
        printf(">> Invalid position!\n");
        return;
    }
    struct Node *target = prev->next;
    prev->next = target->next;
    free(target);
}

void delete_end(struct Node **head)
{
    if (*head == NULL)
    {
        printf(">> List is empty!\n");
        return;
    }
    if ((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *prev = *head;
    while (prev->next->next != *head)
    {
        prev = prev->next;
    }
    free(prev->next);
    prev->next = *head;
}


int main()
{
    printf("\n\n");

    printf("TASK 1: Implementation of Circular Linked List\n");
    printf("-------\n");
    struct Node *c = NULL;
    printf(">> Circular linked list created...");
    printf("\n\n");

    printf("TASK 2: Insertion in Circular Linked List\n");
    printf("-------\n");
    printf(">> Insert 20 at beginning\n");
    insert_beginning(&c, 20);
    display_list(c);
    printf(">> Insert 40 at end\n");
    insert_end(&c, 40);
    display_list(c);
    printf(">> Insert 10 at beginning\n");
    insert_beginning(&c, 10);
    display_list(c);
    printf(">> Insert 30 at position 3\n");
    insert_middle(&c, 30, 3);
    display_list(c);
    printf("\n\n");

    printf("TASK 3: Deletion in Circular Linked List\n");
    printf("-------\n");
    printf(">> Delete position 2\n");
    delete_middle(&c, 2);
    display_list(c);
    printf(">> Delete at the beginning\n");
    delete_beginning(&c);
    display_list(c);
    printf(">> Delete at the end\n");
    delete_end(&c);
    display_list(c);
    printf("\n\n");

    return 0;
}