/*
Write a program to sort an array of integers in ascending order using Merge Sort.
Example: {8, 38, 12, 27, 43, 9, 31, 18, 25}
*/

#include <stdio.h>

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

void merge_sort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(A, low, mid);
        merge_sort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

int main()
{
    printf("----------\n");
    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++)
    {
        printf(">> Enter element #%d: ", i + 1);
        scanf("%d", &A[i]);
    }
    printf("\n");

    printf("----------\n");
    merge_sort(A, 0, N - 1);
    printf("Sorted in Ascending Order using Merge Sort: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("----------\n");

    return 0;
}