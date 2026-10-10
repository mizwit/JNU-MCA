/*
Write a program to sort an array of integers in ascending order using Heap Sort.
Print the array after each major step to see how the heap changes.

Core idea (1-based indexing, as in the notes):
    Parent(i) = i / 2
    Left(i)   = 2i
    Right(i)  = 2i + 1
    Max Heap Property: A[Parent(i)] >= A[i] for every node i other than the root.

Example: {16, 14, 10, 8, 7, 9, 3, 2, 4, 1}
*/

#include <stdio.h>

// The notes use 1-based indexing, but C arrays start at 0.
// So the node 'i' is stored at arr[i - 1].
int parent(int i) { return i / 2; }
int left(int i)   { return 2 * i; }
int right(int i)  { return 2 * i + 1; }

// Print the array. Elements after 'heap_size' are already sorted (shown after '|').
void print_array(int arr[], int size, int heap_size)
{
    for (int i = 0; i < size; i++)
    {
        if (i == heap_size)
        {
            printf("| ");
        }
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Restore the max heap property for the subtree rooted at node 'i'.
// Assumes the left and right subtrees of 'i' are already max heaps.
void max_heapify(int arr[], int heap_size, int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l <= heap_size && arr[l - 1] > arr[largest - 1])
    {
        largest = l;
    }
    if (r <= heap_size && arr[r - 1] > arr[largest - 1])
    {
        largest = r;
    }

    if (largest != i)
    {
        int temp = arr[i - 1];
        arr[i - 1] = arr[largest - 1];
        arr[largest - 1] = temp;
        max_heapify(arr, heap_size, largest);
    }
}

// Convert an unordered array into a max heap.
// Leaves (nodes n/2 + 1 ... n) are already heaps, so start from n/2 and go up to the root.
void build_max_heap(int arr[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        max_heapify(arr, n, i);
        printf(">> Heapify at node %d (value %d): ", i, arr[i - 1]);
        for (int k = 0; k < n; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

void heap_sort(int arr[], int n)
{
    printf(">> Step 1: Build Max Heap\n");
    build_max_heap(arr, n);
    printf(">> Max Heap built (largest element is at the root): ");
    print_array(arr, n, n);
    printf(">> \n");

    printf(">> Step 2: Repeatedly move the root (largest) to the end and heapify\n");
    int heap_size = n;
    for (int i = n; i >= 2; i--)
    {
        // Swap root with the last element of the heap
        int temp = arr[0];
        arr[0] = arr[i - 1];
        arr[i - 1] = temp;
        heap_size--;
        max_heapify(arr, heap_size, 1);

        printf(">> After placing %d at position %d: ", arr[i - 1], i);
        print_array(arr, n, heap_size);
    }
}

int main()
{
    printf("\n\n");

    printf("TASK 1: Heap Sort on the given array\n");
    printf("-------\n");
    int arr1[10] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    int n1 = 10;
    printf(">> Original Array: ");
    for (int i = 0; i < n1; i++) printf("%d ", arr1[i]);
    printf("\n>> (This array is already a max heap, so Step 1 changes nothing.)\n>> \n");
    heap_sort(arr1, n1);
    printf(">> Sorted Array: ");
    for (int i = 0; i < n1; i++) printf("%d ", arr1[i]);
    printf("\n\n\n");

    printf("TASK 2: Heap Sort on an unordered array (to see Build Max Heap in action)\n");
    printf("-------\n");
    int arr2[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int n2 = 10;
    printf(">> Original Array: ");
    for (int i = 0; i < n2; i++) printf("%d ", arr2[i]);
    printf("\n>> \n");
    heap_sort(arr2, n2);
    printf(">> Sorted Array: ");
    for (int i = 0; i < n2; i++) printf("%d ", arr2[i]);
    printf("\n\n\n");

    return 0;
}
