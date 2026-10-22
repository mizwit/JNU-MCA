/*
1. Write a C program to implement Heap Sort.
2. Write a C program to create a Max Heap from a given array.
3. Write a C program to create a Min Heap from a given array.
4. Write a C program to sort an array in ascending order using Heap Sort.
5. Write a C program to sort an array in descending order using Heap Sort.
*/

#include <stdio.h>


/* Function to create Max Heap from a given array */
void max_heapify(int A[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && A[left] > A[largest])
        largest = left;
    if (right < n && A[right] > A[largest])
        largest = right;

    if (largest != i)
    {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        max_heapify(A, largest, n);
    }
}

/* Function to sort array in Ascending Order using Heap Sort */
void heap_sort_ascending(int A[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(A, n, i);
    for (int end = n - 1; end > 0; end--)
    {
        int temp = A[0];
        A[0] = A[end];
        A[end] = temp;
        max_heapify(A, end, 0);
    }
}

/* Function to create Min Heap from a given Array */
void min_heapify(int A[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && A[left] < A[smallest])
        smallest = left;
    if (right < n && A[right] < A[smallest])
        smallest = right;

    if (smallest != i)
    {
        int temp = A[i];
        A[i] = A[smallest];
        A[smallest] = temp;
        min_heapify(A, smallest, n);
    }
}

/* Function to sort array in Desending Order using Heap Sort */
void heap_sort_descending(int A[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        min_heapify(A, n, i);
    for (int end = n - 1; end > 0; end--)
    {
        int temp = A[0];
        A[0] = A[end];
        A[end] = temp;
        min_heapify(A, end, 0);
    }
}

/* Function to Print Array */
void print_array(int A[], int n)
{
    printf(">> ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}


int main()
{
    printf("----------\n");
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        printf(">> Enter element #%d: ", i + 1);
        scanf("%d", &A[i]);
    }
    printf("\n");

    printf("----------\n");
    heap_sort_ascending(A, n);
    printf("Sorted in Ascending Order using Heap Sort: ");
    print_array(A, n);
    printf("\n");

    printf("----------\n");
    heap_sort_descending(A, n);
    printf("Sorted in Descending Order using Heap Sort: ");
    print_array(A, n);
    printf("\n");

    return 0;
}