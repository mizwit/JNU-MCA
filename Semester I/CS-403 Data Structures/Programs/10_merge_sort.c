/*
Implementation of Merge Sort
- Example: {8, 38, 12, 27, 43, 9, 31, 18, 25}
*/

#include <stdio.h>

void print_array(int A[], int n, int start, int end) 
{
    for (int i = 0; i < n; i++) {
        if (i == start)
        {
            printf("[");
        }
        printf("%d", A[i]);
        if (i == end)
        {
            printf("]");
        }
        printf(" ");
    }
    printf("\n");
}

void merge(int A[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];

    for (int x = 0; x < n1; x++)
    {
        L[x] = A[low + x];
    }
    for (int x = 0; x < n2; x++)
    {
        R[x] = A[mid + 1 + x];
    }

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k++] = L[i++];
        } else 
        {
            A[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        A[k++] = L[i++];
    }
    while (j < n2)
    {
        A[k++] = R[j++];
    }
}

void merge_sort(int A[], int n, int low, int high, int *pass)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(A, n, low, mid, pass);
        merge_sort(A, n, mid + 1, high, pass);
        merge(A, low, mid, high);

        (*pass)++;
        printf("Array After Pass #%d: ", *pass);
        print_array(A, n, low, high);
    }
}

int main()
{
    printf("\n");
    printf("TASK: Implementation of Merge Sort\n");
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
    print_array(A, n, 0, n - 1);
    printf("----------\n");

    int pass = 0;
    merge_sort(A, n, 0, n - 1, &pass);
    
    printf("----------\n");
    printf("Sorted Array: ");
    print_array(A, n, 0, n - 1);
    printf("----------\n");

    return 0;
}