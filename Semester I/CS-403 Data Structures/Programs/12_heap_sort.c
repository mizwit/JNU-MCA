/*
1. Implementation of Heap Sort to sort an array in ascending order using Max Heap.
2. Implementation of Heap Sort to sort an array in descending order using Min Heap.
*/

#include <stdio.h>

void print_array(int A[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}


// 1. Implementation of Heap Sort to sort an array in ascending order using Max Heap.
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
        max_heapify(A, n, largest);
    }
}

void heap_sort_ascending(int A[], int n)
{
    int count = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        count++;
        max_heapify(A, n, i);
        printf(">> Max Heapify Operation #%d: ", count);
        print_array(A, n);
    }
    for (int end = n - 1; end > 0; end--)
    {
        int temp = A[0];
        A[0] = A[end];
        A[end] = temp;
        max_heapify(A, end, 0);
    }
}


// 2. Implementation of Heap Sort to sort an array in descending order using Min Heap.
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
        min_heapify(A, n, smallest);
    }
}

void heap_sort_descending(int A[], int n)
{
    int count = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        min_heapify(A, n, i);
        count++;
        printf(">> Max Heapify Operation #%d: ", count);
        print_array(A, n);
    }
    for (int end = n - 1; end > 0; end--)
    {
        int temp = A[0];
        A[0] = A[end];
        A[end] = temp;
        min_heapify(A, end, 0);
    }
}


int main()
{
    printf("\n");
    printf("TASK: Implementation of Heap Sort\n");
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

    printf("----------\n");
    printf("Unsorted Array: ");
    print_array(A, n);
    printf("----------\n\n");

    printf("TASK 1: Heap Sort using Max Heap: \n");
    printf("----------\n");
    heap_sort_ascending(A, n);
    printf("----------\n");
    printf("Sorted in Ascending Order: ");
    print_array(A, n);
    printf("----------\n\n");
    
    printf("TASK 2: Heap Sort using Min Heap: \n");
    printf("----------\n");
    heap_sort_descending(A, n);
    printf("----------\n");
    printf("Sorted in Descending Order: ");
    print_array(A, n);
    printf("----------\n\n");

    return 0;
}