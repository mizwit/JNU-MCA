/*
Write a program to sort an array of integers in ascending order using Insertion Sort.
Example: {7, 35, 12, 48, 7, 26, 19, 41}
*/

#include <stdio.h>

void insertion_sort(int arr[], int N)
{
    for (int i = 1; i <= N; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    printf("----------\n");
    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        printf(">> Enter element #%d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\n");

    printf("----------\n");
    insertion_sort(arr, N);
    printf("Sorted in Ascending Order using Insertion Sort: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("----------\n");

    return 0;
}