/*
Implementation of Insertion Sort
- Example: {7, 35, 12, 48, 7, 26, 19, 41}
*/

#include <stdio.h>

void print_array(int A[], int n) 
{
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertion_sort(int A[], int n, int *shifts)
{   
    int pass = 0;
    for (int i = 1; i < n; i++)
    {
        pass++;
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
            (*shifts)++;
        }
        A[j + 1] = key;
        printf("Array after Pass #%d: ",pass);
        print_array(A, n);
    }
}

int main()
{
    printf("\n");
    printf("TASK: Implementation of Insertion Sort\n");
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
    print_array(A, n);
    printf("----------\n");

    int shifts = 0;
    insertion_sort(A, n, &shifts);
    
    printf("----------\n");
    printf("Sorted Array: ");
    print_array(A, n);
    printf("Total Number of Shifts: %d\n", shifts);
    printf("----------\n");

    return 0;
}