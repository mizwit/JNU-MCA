/*
Implementation of Quick Sort.
- Print the array after each partition step to see how the pivot settles into its final place.
- Example: {42, 84, 75, 20, 60, 10, 90, 50, 15, 30}
*/

#include <stdio.h>

void print_array(int A[], int n, int p)
{
    for (int i = 0; i < n; i++)
    {
        if (i == p)
        {
            printf("[%d] ", A[i]);
        }
        else
        {
            printf("%d ", A[i]);
        }
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int temp = A[i + 1];
    A[i + 1] = A[high];
    A[high] = temp;

    return i + 1;
}

void quick_sort(int A[], int n, int low, int high)
{
    if (low < high)
    {
        int pivot = A[high];
        int p = partition(A, low, high);
        printf(">> Pivot %d placed at index %d: ", pivot, p);
        print_array(A, n, p);

        quick_sort(A, n, low, p - 1);
        quick_sort(A, n, p + 1, high);
    }
}

int main()
{
    printf("\n");
    printf("TASK: Implementation of Quick Sort\n");
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
    printf("Unsorted Array: ");
    print_array(A, n, -1);
    printf("----------\n\n");

    quick_sort(A, n, 0, n - 1);
    printf("\n");

    printf("----------\n");
    printf("Sorted Array: ");
    print_array(A, n, -1);
    printf("----------\n\n");

    return 0;
}
