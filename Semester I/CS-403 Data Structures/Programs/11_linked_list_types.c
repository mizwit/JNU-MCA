/*
Implementation of all types of Linked Lists, each with insertion and deletion
at the beginning, middle (given position) and end:
1. Singly Linked List
2. Doubly Linked List
3. Circular Singly Linked List
4. Circular Doubly Linked List
*/


#include <stdio.h>
#include <stdlib.h>


// Node of a singly / circular singly linked list
struct Node
{
    int data;
    struct Node *next;
};

// Node of a doubly / circular doubly linked list
struct DNode
{
    int data;
    struct DNode *prev;
    struct DNode *next;
};


// Functions to create a new node
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

struct DNode *create_dnode(int data)
{
    struct DNode *new_node = malloc(sizeof(struct DNode));
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


// ======================= 1. SINGLY LINKED LIST =======================

void display_singly(struct Node *head)
{
    printf(">> ");
    for (struct Node *node = head; node != NULL; node = node->next)
    {
        printf("%d -> ", node->data);
    }
    printf("NULL\n");
}

void singly_insert_beginning(struct Node **head, int data)
{
    struct Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void singly_insert_end(struct Node **head, int data)
{
    struct Node *new_node = create_node(data);
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
}

// Insert at position 'pos' (1-based)
void singly_insert_middle(struct Node **head, int data, int pos)
{
    if (pos < 1)
    {
        printf(">> Invalid position!\n");
        return;
    }
    if (pos == 1)
    {
        singly_insert_beginning(head, data);
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
    struct Node *new_node = create_node(data);
    new_node->next = temp->next;
    temp->next = new_node;
}

void singly_delete_beginning(struct Node **head)
{
    if (*head == NULL)
    {
        printf(">> List is empty!\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void singly_delete_end(struct Node **head)
{
    if (*head == NULL)
    {
        printf(">> List is empty!\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *prev = *head;
    while (prev->next->next != NULL)
    {
        prev = prev->next;
    }
    free(prev->next);
    prev->next = NULL;
}

// Delete node at position 'pos' (1-based)
void singly_delete_middle(struct Node **head, int pos)
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
        singly_delete_beginning(head);
        return;
    }
    struct Node *prev = *head;
    for (int i = 1; i < pos - 1 && prev != NULL; i++)
    {
        prev = prev->next;
    }
    if (prev == NULL || prev->next == NULL)
    {
        printf(">> Invalid position!\n");
        return;
    }
    struct Node *target = prev->next;
    prev->next = target->next;
    free(target);
}


// ======================= 2. DOUBLY LINKED LIST =======================

void display_doubly(struct DNode *head)
{
    printf(">> NULL <-> ");
    for (struct DNode *node = head; node != NULL; node = node->next)
    {
        printf("%d <-> ", node->data);
    }
    printf("NULL\n");
}

void doubly_insert_beginning(struct DNode **head, int data)
{
    struct DNode *new_node = create_dnode(data);
    new_node->next = *head;
    if (*head != NULL)
    {
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void doubly_insert_end(struct DNode **head, int data)
{
    struct DNode *new_node = create_dnode(data);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    struct DNode *tail = *head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = new_node;
    new_node->prev = tail;
}

void doubly_insert_middle(struct DNode **head, int data, int pos)
{
    if (pos < 1)
    {
        printf(">> Invalid position!\n");
        return;
    }
    if (pos == 1)
    {
        doubly_insert_beginning(head, data);
        return;
    }
    struct DNode *temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf(">> Invalid position!\n");
        return;
    }
    struct DNode *new_node = create_dnode(data);
    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
}

void doubly_delete_beginning(struct DNode **head)
{
    if (*head == NULL)
    {
        printf(">> List is empty!\n");
        return;
    }
    struct DNode *temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }
    free(temp);
}

void doubly_delete_end(struct DNode **head)
{
    if (*head == NULL)
    {
        printf(">> List is empty!\n");
        return;
    }
    struct DNode *tail = *head;
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

void doubly_delete_middle(struct DNode **head, int pos)
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
        doubly_delete_beginning(head);
        return;
    }
    struct DNode *target = *head;
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


// =================== 3. CIRCULAR SINGLY LINKED LIST ===================

void display_circular(struct Node *head)
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

void circular_insert_beginning(struct Node **head, int data)
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

void circular_insert_end(struct Node **head, int data)
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

void circular_insert_middle(struct Node **head, int data, int pos)
{
    if (pos < 1)
    {
        printf(">> Invalid position!\n");
        return;
    }
    if (pos == 1)
    {
        circular_insert_beginning(head, data);
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

void circular_delete_beginning(struct Node **head)
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

void circular_delete_end(struct Node **head)
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

void circular_delete_middle(struct Node **head, int pos)
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
        circular_delete_beginning(head);
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


// ================== 4. CIRCULAR DOUBLY LINKED LIST ==================

void display_circular_doubly(struct DNode *head)
{
    if (head == NULL)
    {
        printf(">> (empty)\n");
        return;
    }
    printf(">> ");
    struct DNode *node = head;
    do
    {
        printf("%d <-> ", node->data);
        node = node->next;
    } while (node != head);
    printf("(back to head)\n");
}

void cdll_insert_beginning(struct DNode **head, int data)
{
    struct DNode *new_node = create_dnode(data);
    if (*head == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        *head = new_node;
        return;
    }
    struct DNode *last = (*head)->prev;
    new_node->next = *head;
    new_node->prev = last;
    last->next = new_node;
    (*head)->prev = new_node;
    *head = new_node;
}

void cdll_insert_end(struct DNode **head, int data)
{
    struct DNode *new_node = create_dnode(data);
    if (*head == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        *head = new_node;
        return;
    }
    struct DNode *last = (*head)->prev;
    new_node->next = *head;
    new_node->prev = last;
    last->next = new_node;
    (*head)->prev = new_node;
}

void cdll_insert_middle(struct DNode **head, int data, int pos)
{
    if (pos < 1)
    {
        printf(">> Invalid position!\n");
        return;
    }
    if (pos == 1)
    {
        cdll_insert_beginning(head, data);
        return;
    }
    if (*head == NULL)
    {
        printf(">> Invalid position!\n");
        return;
    }
    struct DNode *temp = *head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == *head)
        {
            printf(">> Invalid position!\n");
            return;
        }
    }
    struct DNode *new_node = create_dnode(data);
    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next->prev = new_node;
    temp->next = new_node;
}

void cdll_delete_beginning(struct DNode **head)
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
    struct DNode *temp = *head;
    struct DNode *last = temp->prev;
    *head = temp->next;
    (*head)->prev = last;
    last->next = *head;
    free(temp);
}

void cdll_delete_end(struct DNode **head)
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
    struct DNode *last = (*head)->prev;
    last->prev->next = *head;
    (*head)->prev = last->prev;
    free(last);
}

void cdll_delete_middle(struct DNode **head, int pos)
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
        cdll_delete_beginning(head);
        return;
    }
    struct DNode *target = *head;
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


int main()
{
    printf("\n\n");

    printf("TASK 1: Singly Linked List\n");
    printf("-------\n");
    struct Node *s = NULL;
    printf(">> Insert 20 at beginning, 40 at end, 10 at beginning, 30 at position 3\n");
    singly_insert_beginning(&s, 20);
    singly_insert_end(&s, 40);
    singly_insert_beginning(&s, 10);
    singly_insert_middle(&s, 30, 3);
    display_singly(s);
    printf(">> Delete position 2, then beginning, then end\n");
    singly_delete_middle(&s, 2);
    singly_delete_beginning(&s);
    singly_delete_end(&s);
    display_singly(s);
    printf(">> Trying to insert at invalid position 5...\n");
    singly_insert_middle(&s, 99, 5);
    printf("\n\n");

    printf("TASK 2: Doubly Linked List\n");
    printf("-------\n");
    struct DNode *d = NULL;
    printf(">> Insert 20 at beginning, 40 at end, 10 at beginning, 30 at position 3\n");
    doubly_insert_beginning(&d, 20);
    doubly_insert_end(&d, 40);
    doubly_insert_beginning(&d, 10);
    doubly_insert_middle(&d, 30, 3);
    display_doubly(d);
    printf(">> Delete position 2, then beginning, then end\n");
    doubly_delete_middle(&d, 2);
    doubly_delete_beginning(&d);
    doubly_delete_end(&d);
    display_doubly(d);
    printf("\n\n");

    printf("TASK 3: Circular Singly Linked List\n");
    printf("-------\n");
    struct Node *c = NULL;
    printf(">> Insert 20 at beginning, 40 at end, 10 at beginning, 30 at position 3\n");
    circular_insert_beginning(&c, 20);
    circular_insert_end(&c, 40);
    circular_insert_beginning(&c, 10);
    circular_insert_middle(&c, 30, 3);
    display_circular(c);
    printf(">> Delete position 2, then beginning, then end\n");
    circular_delete_middle(&c, 2);
    circular_delete_beginning(&c);
    circular_delete_end(&c);
    display_circular(c);
    printf("\n\n");

    printf("TASK 4: Circular Doubly Linked List\n");
    printf("-------\n");
    struct DNode *cd = NULL;
    printf(">> Insert 20 at beginning, 40 at end, 10 at beginning, 30 at position 3\n");
    cdll_insert_beginning(&cd, 20);
    cdll_insert_end(&cd, 40);
    cdll_insert_beginning(&cd, 10);
    cdll_insert_middle(&cd, 30, 3);
    display_circular_doubly(cd);
    printf(">> Delete position 2, then beginning, then end\n");
    cdll_delete_middle(&cd, 2);
    cdll_delete_beginning(&cd);
    cdll_delete_end(&cd);
    display_circular_doubly(cd);
    printf("\n\n");

    return 0;
}
