/*
Problem: Find a contiguous part of an array of numbers that gives the largest possible sum.
*/

#include <stdio.h>

int print_subarray(int A[], int n, int start, int end)
{
    printf("[");
    for (int i = start; i < end; i++)
    {
        printf("%d, ", A[i]);
    }
    printf("%d]\n", A[end]);
}

int max_subarray_sum(int A[], int n)
{
    int current_sum = A[0];
    int max_sum = A[0];
    int low = 0, high = 0;

    for (int i = 1; i < n; i++)
    {
        if (current_sum < 0)
        {
            current_sum = A[i];
            low = i;
        }
        else
        {
            current_sum += A[i];
        }

        if (current_sum > max_sum)
        {
            max_sum = current_sum;
            high = i;
        }
    }
    printf("Subarray: ");
    print_subarray(A, n, low, high);
    return max_sum;
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
    printf("Array: ");
    print_subarray(A, n, 0, n - 1);
    printf("Sum: %d\n", max_subarray_sum(A, n));
    printf("\n");
}