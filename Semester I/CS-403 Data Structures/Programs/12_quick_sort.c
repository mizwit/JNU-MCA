/*
Write a program to sort an array of integers in ascending order using Quick Sort.
Print the array after each partition step to see how the pivot settles into its final place.

Core idea (last element is the pivot / key):
    i = low - 1
    for j = low ... high - 1:
        if a[j] < key:
            i++
            swap a[i] and a[j]
    after the loop, swap a[i + 1] and the key (pivot)
    => pivot is now at its final sorted position, with smaller elements on its left
       and larger elements on its right.

Example: {42, 84, 75, 20, 60, 10, 90, 50, 05, 30}
*/

#include <stdio.h>

// Print the array, highlighting the pivot's final position with [ ]
void print_array(int arr[], int size, int pivot_index)
{
    printf(">> ");
    for (int i = 0; i < size; i++)
    {
        if (i == pivot_index)
        {
            printf("[%d] ", arr[i]);
        }
        else
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

// Partition arr[low..high] around the last element (pivot).
// Returns the final index of the pivot.
int partition(int arr[], int low, int high)
{
    int key = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < key)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place the pivot right after the last smaller element
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quick_sort(int arr[], int low, int high, int size)
{
    if (low < high)
    {
        int key = arr[high];
        int p = partition(arr, low, high);
        printf(">> Partition of indices %d to %d, pivot %d placed at index %d:\n", low, high, key, p);
        print_array(arr, size, p);

        quick_sort(arr, low, p - 1, size);
        quick_sort(arr, p + 1, high, size);
    }
}

int main()
{
    int arr[10] = {42, 84, 75, 20, 60, 10, 90, 50, 5, 30};
    int N = 10;

    printf("\n\n");
    printf("----------\n");
    printf("Unsorted Array: ");
    for (int i = 0; i < N; i++) printf("%d ", arr[i]);
    printf("\n----------\n");
    printf("(The number in [ ] is the pivot, now in its final sorted position.)\n\n");

    quick_sort(arr, 0, N - 1, N);

    printf("\n----------\n");
    printf("Sorted Array: ");
    for (int i = 0; i < N; i++) printf("%d ", arr[i]);
    printf("\n----------\n\n");

    return 0;
}
