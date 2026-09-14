/*
Write a C program to sort an array using Bubble Sort:
1. Sort the array in ascendng order.
2. Count the total number of comparisions and swaps.
3. After each pass, print the current array.
4. Determine and print whatever the original array was.
    - Already sorted
    - Nearly sorted
    - Completely unsorted
5. Print the pass number in which array became sorted.
*/

#include <stdio.h>

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int N = 10;
    int arr[10] = {83, 4, 16, 47, 33, 38, 92, 19, 25, 2};
    
    printf("Unsorted Array: ");
    print_array(arr, N);
    printf("----------\n");
    
    int total_comps = 0, total_swaps = 0, pass_number = 0;
    for (int i = 0; i < N - 1; i++)
    {
        pass_number++;
        for (int j = 0; j < N - 1 - i; j++)
        {   
            total_comps++;
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                total_swaps++;
            }
        }
        printf("Array after Pass #%d: ",pass_number);
        print_array(arr, N);
    }
    printf("----------\n");
    
    printf("Sorted Array: ");
    print_array(arr, N);
    printf("----------\n");
    
    printf("Total Number of Comparisions: %d\n", total_comps);
    printf("Total Number of Swaps: %d\n", total_swaps);
    printf("Passes after it became sorted: %d\n", pass_number);
    
    return 0;
}
