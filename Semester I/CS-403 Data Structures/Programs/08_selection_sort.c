/*
Implementation of Selection Sort
- Sort the array in ascendng order.
- Count the total number of comparisions and swaps.
- Handle duplicate elements correctly.
- Example: 
    Input:
    - Enter number of elements: 7
    - {5, 2, 8, 2, 1, 5, 1}
    Output:
    - Sorted Array: {1, 1, 2, 2, 5, 5, 8}
    - Total Comparisions: 21
    - Total Swaps: 4
*/

#include <stdio.h>

void print_array(int A[], int n) 
{
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selection_sort(int A[], int n, int *comps, int *swaps) 
{
    int pass = 0;
    for (int i = 0; i < n - 1; i++)
    {
        pass++;
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            (*comps)++;
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = A[min];
            A[min] = A[i];
            A[i] = temp;
            (*swaps)++;
        }
        printf("Array after Pass #%d: ",pass);
        print_array(A, n);
    }
}

int main()
{
    printf("\n");
    printf("TASK: Implementation of Selection Sort\n");
    printf("----------\n");
    int n;
    printf("Enter number of elements: ");
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
    printf("----------\n");

    int comps = 0, swaps = 0;
    selection_sort(A, n, &comps, &swaps);

    printf("----------\n");
    printf("Sorted Array: ");
    print_array(A, n);
    printf("----------\n");

    printf("Total Number of Comparisions: %d\n", comps);
    printf("Total Number of Swaps: %d\n", swaps);
    printf("----------\n");

    return 0;
}