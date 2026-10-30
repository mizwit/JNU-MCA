/*
Find an element in an array and return its index using Linear Search.
*/

#include <stdio.h>

int linear_search(int A[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] ==  key)
        {
            return key;
        }
    }
    return -1;  
}

int main() 
{
    printf("\n");
    printf("TASK: Implementation of Linear Search\n");
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

    printf("----------\n");
    int index = linear_search(A, n, key);
    if (index != -1) 
    {
        printf("Element '%d' found at Index: %d\n", key, index);
    } else 
    {
        printf("Element '%d' is not present in the array.\n", key);
    }
    printf("----------\n\n");

    return 0;
}