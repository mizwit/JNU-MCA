/*
Write a C Program to implement Selection Sort that sorts and array in ascending order and simultaneously counts the number of comparisions and swaps performed. The program should handle duplicate elements correctly and use a separate function for sorting.
Input: 
- Enter number of elements: 7
- Enter 7 elements
- {5, 2, 8, 2, 1, 5, 1}
Output:
- Sorted Array: {1, 1, 2, 2, 5, 5, 8}
- Total Comparisions: 21
- Total Swaps: 4
*/

#include <stdio.h>

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection_sort(int arr[], int size, int *total_comps, int *total_swaps) {
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            (*total_comps)++;
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
            (*total_swaps)++;
        }
    }
}

int main()
{
    printf("----------\n");
    int N;
    printf("Enter number of elements: ");
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        printf(">> Enter element #%d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("----------\n");

    printf("Unsorted Array: ");
    print_array(arr, N);
    int total_comps = 0, total_swaps = 0;
    selection_sort(arr, N, &total_comps, &total_swaps);
    printf("Sorted Array: ");
    print_array(arr, N);
    printf("----------\n");

    printf("Total Number of Comparisions: %d\n", total_comps);
    printf("Total Number of Swaps: %d\n", total_swaps);
    printf("----------\n");

    return 0;
}