/*
Implementation of Bubble Sort
- Sort the array in ascendng order.
- Count the total number of comparisions and swaps.
- After each pass, print the current array.
*/

#include <stdio.h>

void print_array(int A[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubble_sort(int A[], int n, int *comps, int *swaps) 
{
    int pass = 0;
    for (int i = 0; i < n - 1; i++)
    {
        pass++;
        for (int j = 0; j < n - 1 - i; j++)
        {   
            (*comps)++;
            if (A[j] > A[j + 1])
            {
                int temp = A[j + 1];
                A[j + 1] = A[j];
                A[j] = temp;
                (*swaps)++;
            }
        }
        printf("Array after Pass #%d: ",pass);
        print_array(A, n);
    }
}

int main()
{
    printf("\n");
    printf("TASK: Implementation of Bubble Sort\n");
    printf("----------\n");
    int n;
    printf("Size of the array: ");
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element #%d: ", i + 1);
        scanf("%d", &A[i]);
    }

    printf("----------\n");
    printf("Unsorted Array: ");
    print_array(A, n);
    printf("----------\n");
    
    int comps = 0, swaps = 0;
    bubble_sort(A, n, &comps, &swaps);

    printf("----------\n");    
    printf("Sorted Array: ");
    print_array(A, n);
    printf("----------\n");
    
    printf("Total Number of Comparisions: %d\n", comps);
    printf("Total Number of Swaps: %d\n", swaps);
    printf("----------\n");
    
    return 0;
}