/* 
1. Implementation of Singly Linked List.
2. Insertion at the beginning, at a given position, and at the end of a singly linked list.
3. Deletion at the beginning, at a given position, and at the end of a singly linked list.
4. Reverse a singly linked list without creating a new linked list.
5. Remove duplicate elements from a sorted singly linked list.
6. Given a value 'x', delete every node containing 'x' from a singly linked list.
7. Join two singly linked list into one list.
8. Determine whether two singly linked list contain the same elements in the same order.
*/


#include <stdio.h>
#include <stdlib.h>


// 1. Implementation of a Singly Linked List
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
    printf(">> ");
    for (struct Node *node = head; node != NULL; node = node->next)
    {
        printf("%d -> ", node->data);
    }
    printf("NULL\n");
}


// 2. Insertion in Singly Linked List
void insert_beginning(struct Node **head, int data)
{
    struct Node *new_node = create_node(data);
    new_node->next = *head;
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
    struct Node *new_node = create_node(data);
    new_node->next = temp->next;
    temp->next = new_node;
}

void insert_end(struct Node **head, int data)
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


// 3. Deletion in Singly Linked List
void delete_beginning(struct Node **head)
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

void delete_end(struct Node **head)
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


// 4. Reverse a single linked list
void reverse_linked_list(struct Node **head)
{
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current; 
        current = next;
    }
    *head = prev;
}


// 5. Remove duplicate elements from a sorted singly linked list
void sort_linked_list(struct Node **head)
{
    if (*head == NULL)
    {
        printf(">> The linked list is empty. No sorting needed.\n");
        return;
    }
    struct Node *i = *head;
    while (i != NULL)
    {
        struct Node *current = *head;
        while (current->next != NULL)
        {
            if (current->data > current->next->data)
            {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
            current = current->next;
        }
        i = i->next;
    }
}

void remove_duplicates(struct Node **head)
{
    if (*head == NULL)
    {
        printf(">> The linked list is empty. No duplicates to remove.\n");
        return;
    }
    struct Node *current = *head;
    while (current != NULL && current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            struct Node *duplicate_node = current->next;
            current->next = current->next->next;
            free(duplicate_node);
        }
        else
        {
            current = current->next;
        }
    }
}


// 6. Given a value 'x', delete every node containing 'x' from a singly linked list
void delete_nodes(struct Node **head, int x)
{
    if (*head == NULL)
    {
        printf(">> The linked list is empty. No nodes to delete.\n");
        return;
    }
    struct Node *current = *head;
    struct Node *prev = NULL;

    while (current != NULL)
    {
        if (current->data == x)
        {
            if (prev == NULL)
            {
                *head = current->next;
                free(current);
                current = *head;
            }
            else
            {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}


// 7. Join two singly linked list into one list.
void join_linked_lists(struct Node **head1, struct Node **head2)
{
    if (*head1 == NULL)
    {
        *head1 = *head2;
        *head2 = NULL;
        return;
    }
    struct Node *tail = *head1;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = *head2;
    *head2 = NULL;
}


// 8. Compare two linked lists for equality.
void compare_linked_lists(struct Node *head1, struct Node *head2)
{
    struct Node *current1 = head1;
    struct Node *current2 = head2;

    while (current1 != NULL && current2 != NULL)
    {
        if (current1->data != current2->data)
        {
            printf(">> The linked lists are NOT equal.\n");
            return;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    if (current1 == NULL && current2 == NULL)
    {
        printf(">> The linked lists are equal.\n");
    }
    else
    {
        printf(">> The linked lists are NOT equal.\n");
    }
}


int main()
{
    printf("\n\n");

    printf("TASK 1: Implementation of Singly Linked List\n");
    printf("-------\n");
    struct Node *s = NULL;
    printf(">> Singly linked list created...");
    printf("\n\n");

    printf("TASK 2: Insertion in Singly Linked List\n");
    printf("-------\n");
    printf(">> Insert 20 at beginning\n");
    insert_beginning(&s, 20);
    display_list(s);
    printf(">> Insert 40 at end\n");
    insert_end(&s, 40);
    display_list(s);
    printf(">> Insert 10 at beginning\n");
    insert_beginning(&s, 10);
    display_list(s);
    printf(">> Insert 30 at position 3\n");
    insert_middle(&s, 30, 3);
    display_list(s);
    printf("\n\n");

    printf("TASK 3: Deletion in Singly Linked List\n");
    printf("-------\n");
    printf(">> Delete position 2\n");
    delete_middle(&s, 2);
    display_list(s);
    printf(">> Delete at the beginning\n");
    delete_beginning(&s);
    display_list(s);
    printf(">> Delete at the end\n");
    delete_end(&s);
    display_list(s);
    printf("\n\n");

    printf("TASK 4: Reverse a singly linked list without creating a new linked list.\n");
    printf("-------\n");
    printf(">> Insert 20 at beginning, 30 at end, 10 at beginning\n");
    insert_beginning(&s, 20);
    insert_end(&s, 30);
    insert_beginning(&s, 10);
    display_list(s);
    printf(">> Reversing the linked list...\n");
    reverse_linked_list(&s);
    printf(">> Reversed Linked List: \n");
    display_list(s);
    printf("\n\n");

    printf("TASK 5: Remove duplicate elements from a sorted linked list.\n");
    printf("-------\n");
    printf(">> Sorting the linked list...\n");
    sort_linked_list(&s);
    printf(">> Sorted Linked List: \n");
    display_list(s);
    printf(">> \n");
    printf(">> Removing duplicate elements...\n");
    remove_duplicates(&s);
    printf(">> Linked List after removing duplicates: \n");
    display_list(s);
    printf("\n\n");

    printf("TASK 6: Given a value 'x', delete every node containing 'x'.\n");
    printf("-------\n");
    int x = 20;
    printf(">> Deleting every node containing the value '%d'...\n", x);
    delete_nodes(&s, x);
    printf(">> Linked List after deleting nodes with value '%d': \n", x);
    display_list(s);
    printf("\n\n");

    printf("TASK 7: Join two linked list into one list.\n");
    printf("-------\n");
    struct Node *s2 = NULL;
    printf(">> Creating List with Insert 15 at beginning, 25 at end\n");
    insert_beginning(&s2, 15);
    insert_end(&s2, 25);
    printf(">> First Linked List: \n");
    display_list(s);
    printf(">> Second Linked List: \n");
    display_list(s2);
    printf(">> Joining the two linked lists...\n");
    join_linked_lists(&s, &s2);
    printf(">> Joined Linked List: \n");
    display_list(s);
    printf("\n\n");

    printf("TASK 8: Determine whether two linked list contain the same elements in the same order.\n");
    printf("-------\n");
    struct Node *s3 = NULL;
    printf(">> Creating List with Insert 30 at beginning, 15 at end\n");
    insert_beginning(&s3, 30);
    insert_end(&s3, 15);    
    printf(">> First Linked List: \n");
    display_list(s);
    printf(">> Second Linked List: \n");
    display_list(s3);
    printf(">> Comparing the two linked lists...\n");
    compare_linked_lists(s, s3);
    printf(">> \n");
    printf(">> Updating new list with Insert 10 at beginning, 25 at end\n");
    insert_beginning(&s3, 10);
    insert_end(&s3, 25);
    printf(">> First Linked List: \n");
    display_list(s);
    printf(">> Second Linked List: \n");
    display_list(s3);
    printf(">> Comparing the two linked lists...\n");
    compare_linked_lists(s, s3);
    printf("\n\n");
    
    return 0;
}