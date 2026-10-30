/*
1. Find an element in a sorted array and return its index using Binary Search.
2. Find the first occurrence of an element in a sorted array using Binary Search.
3. Find the last occurence of an element in a sorted array using Binary Search.
*/

#include <stdio.h>

// 1. Find an element in a sorted array and return its index using Binary Search.
int binary_search(int A[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (A[mid] == key)
        {
            return mid;
        } else if (A[mid] < key)
        {
            low = mid + 1;
        } else
        {
            high = mid - 1;
        }
    }
    return -1;  
}

// 2. Find the first occurrence of an element in a sorted array using Binary Search.
int find_first(int A[], int n, int key) 
{
    int low = 0, high = n - 1;
    int first = -1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2; 
        if (A[mid] == key) 
        {
            first = mid;
            high = mid - 1;
        } else if (A[mid] < key) 
        {
            low = mid + 1;
        } else 
        {
            high = mid - 1;
        }
    }
    return first;
}

// 3. Find the last occurence of an element in a sorted array using Binary Search.
int find_last(int A[], int n, int key) 
{
    int low = 0, high = n - 1;
    int last = -1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (A[mid] == key) 
        {
            last = mid;
            low = mid + 1;
        } else if (A[mid] < key) 
        {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return last;
}

int main() 
{
    printf("\n");
    printf("TASK: Implementation of Binary Search\n");
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
    int key;
    printf("Enter the key element: ");
    scanf("%d", &key);
    printf("\n");

    int index = binary_search(A, n, key);
    int first = find_first(A, n, key);
    int last = find_last(A, n, key);
    
    printf("----------\n");
    if (index != -1) 
    {
        printf("Element '%d' found at Index: %d\n", key, index);
        printf("First Occurrence is at Index: %d\n", first);
        printf("Last Occurrence is at Index: %d\n", last);
    } else 
    {
        printf("Element '%d' is not present in the array.\n", key);
    }
    printf("----------\n\n");

    return 0;
}