/* 
1. Create a singly linked list with 'n' elements and display all of its elements.
2. Insert a new node at the beginning and end of a singly linked list.
3. Reverse a singly linked list without creating a new linked list.
4. Remove duplicate elements from a sorted linked list.
5. Given a value 'x', delete every node containing 'x'.
6. Join two linked list into one list.
7. Determine whether two linked list contain the same elements in the same order.
*/


#include <stdio.h>
#include <stdlib.h>


// Define a struct representing node of a singly linked list.
struct Node
{
    int data;
    struct Node *next;
};


// Function to create a singly linked list with 'n' number of nodes.
void create_linked_list(int n, struct Node **head)
{
    struct Node *tail = NULL;
    struct Node *new_node = NULL;

    for (int i = 0; i < n; i++)
    {
        new_node = malloc(sizeof(struct Node));
        if (new_node == NULL)
        {
            printf("Out of memory\n");
            return;
        }
        new_node->data = (i + 1) * 10;
        new_node->next = NULL;

        if (*head == NULL)
        {
            *head = new_node;
            tail = *head;
        }
        else
        {
            tail->next = new_node;
            tail = tail->next;
        }
    }
}


// Function to display all elements of a singly linked list.
void display_linked_list(struct Node *head)
{    
    struct Node* node = head;
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}


// Function to insert a new node at the beginning of a singly linked list.
void insert_at_beginning(struct Node **head, int new_data)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Out of memory\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}


// Function to insert a new node at the end of a singly linked list.
void insert_at_end(struct Node **head, int new_data)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Out of memory\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        struct Node *tail = *head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = new_node;
    }
}


// Function to reverse a single linked list
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


// Function to sort a linked list using bubble sort algorithm
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


// Function to remove duplicate elements from a sorted linked list.
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


// Function to delete every node containing a specific value 'x' from the linked list.
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


// Function to join two linked lists into one list.
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


// Function to compare two linked lists for equality.
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
    struct Node *head = NULL;
    struct Node *head2 = NULL;
    printf("\n\n");
    
    printf("TASK 1: Create a singly linked list with 'n' elements and display all of its elements.\n");
    printf("-------\n");
    int n = 3;
    printf(">> Creating a linked list with %d elements...\n", n);
    create_linked_list(n, &head);
    printf(">> Created Linked List: \n>> ");
    display_linked_list(head);
    printf("\n\n");

    printf("TASK 2: Insert a new node at the beginning and end of a singly linked list.\n");
    printf("-------\n");
    int beginning = 10;
    int end = 40;
    printf(">> Inserting a new node with data '%d' at the beginning of the linked list...\n", beginning);
    insert_at_beginning(&head, beginning);
    printf(">> Linked List after insertion at the beginning: \n>> ");
    display_linked_list(head);
    printf(">> \n");
    printf(">> Inserting a new node with data '%d' at the end of the linked list...\n", end);
    insert_at_end(&head, end);
    printf(">> Linked List after insertion at the end: \n>> ");
    display_linked_list(head);
    printf("\n\n");

    printf("TASK 3: Reverse a singly linked list without creating a new linked list.\n");
    printf("-------\n");
    printf(">> Reversing the linked list...\n");
    reverse_linked_list(&head);
    printf(">> Reversed Linked List: \n>> ");
    display_linked_list(head);
    printf("\n\n");

    printf("TASK 4: Remove duplicate elements from a sorted linked list.\n");
    printf("-------\n");
    printf(">> Sorting the linked list...\n");
    sort_linked_list(&head);
    printf(">> Sorted Linked List: \n>> ");
    display_linked_list(head);
    printf(">> \n");
    printf(">> Removing duplicate elements...\n");
    remove_duplicates(&head); // Assuming the list is sorted.
    printf(">> Linked List after removing duplicates: \n>> ");
    display_linked_list(head);
    printf("\n\n");

    printf("TASK 5: Given a value 'x', delete every node containing 'x'.\n");
    printf("-------\n");
    int x = 20;
    printf(">> Deleting every node containing the value '%d'...\n", x);
    delete_nodes(&head, x);
    printf(">> Linked List after deleting nodes with value '%d': \n>> ", x);
    display_linked_list(head);
    printf("\n\n");

    printf("TASK 6: Join two linked list into one list.\n");
    printf("-------\n");
    create_linked_list(2, &head2);
    printf(">> First Linked List: \n>> ");
    display_linked_list(head);
    printf(">> Second Linked List: \n>> ");
    display_linked_list(head2);
    printf(">> Joining the two linked lists...\n");
    join_linked_lists(&head, &head2);
    printf(">> Joined Linked List: \n>> ");
    display_linked_list(head);
    printf("\n\n");

    printf("TASK 7: Determine whether two linked list contain the same elements in the same order.\n");
    printf("-------\n");
    create_linked_list(5, &head2);
    printf(">> First Linked List: \n>> ");
    display_linked_list(head);
    printf(">> Second Linked List: \n>> ");
    display_linked_list(head2);
    printf(">> Comparing the two linked lists...\n");
    compare_linked_lists(head, head2);
    printf(">> \n");
    printf(">> Firt Linked List: \n>> ");
    display_linked_list(head);
    printf(">> Second Linked List: \n>> ");
    display_linked_list(head);
    printf(">> Comparing the two linked lists...\n");
    compare_linked_lists(head, head);
    printf("\n\n");
    
    return 0;
}