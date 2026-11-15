/*
1. Implementation of Circular Doubly Linked List.
2. Insertion at the beginning, at a given position, and at the end of a circular doubly linked list.
3. Deletion at the beginning, at a given position, and at the end of a circular doubly linked list.
*/


#include <stdio.h>
#include <stdlib.h>


// 1. Implementation of Circular Doubly Linked List
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
    if (head == NULL)
    {
        printf(">> (empty)\n");
        return;
    }
    printf(">> ");
    struct Node *node = head;
    do
    {
        printf("%d <-> ", node->data);
        node = node->next;
    } while (node != head);
    printf("(head)\n");
}


// 2. Insertion in Circular Doubly Linked List
void insert_beginning(struct Node **head, int data)
{
    struct Node *new_node = create_Node(data);
    if (*head == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        *head = new_node;
        return;
    }
    struct Node *last = (*head)->prev;
    new_node->next = *head;
    new_node->prev = last;
    last->next = new_node;
    (*head)->prev = new_node;
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
    struct Node *new_node = create_Node(data);
    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next->prev = new_node;
    temp->next = new_node;
}

void insert_end(struct Node **head, int data)
{
    struct Node *new_node = create_Node(data);
    if (*head == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        *head = new_node;
        return;
    }
    struct Node *last = (*head)->prev;
    new_node->next = *head;
    new_node->prev = last;
    last->next = new_node;
    (*head)->prev = new_node;
}


// 3. Deletion in Circular Doubly Linked List
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
    struct Node *temp = *head;
    struct Node *last = temp->prev;
    *head = temp->next;
    (*head)->prev = last;
    last->next = *head;
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
    for (int i = 1; i < pos; i++)
    {
        target = target->next;
        if (target == *head)
        {
            printf(">> Invalid position!\n");
            return;
        }
    }
    target->prev->next = target->next;
    target->next->prev = target->prev;
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
    struct Node *last = (*head)->prev;
    last->prev->next = *head;
    (*head)->prev = last->prev;
    free(last);
}


int main()
{
    printf("\n\n");

    printf("TASK 1: Implementation of Circular Doubly Linked List\n");
    printf("-------\n");
    struct Node *cd = NULL;
    printf(">> Circular doubly linked list created...");
    printf("\n\n");

    printf("TASK 2: Insertion in Circular Doubly Linked List\n");
    printf("-------\n");
    printf(">> Insert 20 at beginning\n");
    insert_beginning(&cd, 20);
    display_list(cd);
    printf(">> Insert 40 at end\n");
    insert_end(&cd, 40);
    display_list(cd);
    printf(">> Insert 10 at beginning\n");
    insert_beginning(&cd, 10);
    display_list(cd);
    printf(">> Insert 30 at position 3\n");
    insert_middle(&cd, 30, 3);
    display_list(cd);
    printf("\n\n");

    printf("TASK 3: Deletion in Circular Doubly Linked List\n");
    printf("-------\n");
    printf(">> Delete position 2\n");
    delete_middle(&cd, 2);
    display_list(cd);
    printf(">> Delete at the beginning\n");
    delete_beginning(&cd);
    display_list(cd);
    printf(">> Delete at the end\n");
    delete_end(&cd);
    display_list(cd);
    printf("\n\n");

    return 0;
}