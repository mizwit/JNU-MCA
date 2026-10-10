/*
1. Multiplication of two matrices.
2. Multiplication of two arrays.
*/


#include <stdio.h>
#define MAX 10


// Function to display a matrix
void display_matrix(int m[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        printf(">> ");
        for (int j = 0; j < cols; j++)
        {
            printf("%4d ", m[i][j]);
        }
        printf("\n");
    }
}


// Function to multiply two matrices: C = A x B
// Possible only when columns of A == rows of B
int multiply_matrices(int A[MAX][MAX], int r1, int c1, int B[MAX][MAX], int r2, int c2, int C[MAX][MAX])
{
    if (c1 != r2)
    {
        printf(">> Multiplication not possible (columns of A != rows of B)!\n");
        return 0;
    }
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return 1;
}


// Function to multiply two arrays element by element: C[i] = A[i] * B[i]
void multiply_arrays(int A[], int B[], int C[], int size)
{
    for (int i = 0; i < size; i++)
    {
        C[i] = A[i] * B[i];
    }
}


int main()
{
    printf("\n\n");

    printf("TASK 1: Multiplication of two matrices\n");
    printf("-------\n");
    int A[MAX][MAX] = {{1, 2, 3}, {4, 5, 6}};     // 2 x 3
    int B[MAX][MAX] = {{7, 8}, {9, 10}, {11, 12}}; // 3 x 2
    int C[MAX][MAX];
    int r1 = 2, c1 = 3, r2 = 3, c2 = 2;

    printf(">> Matrix A (%d x %d):\n", r1, c1);
    display_matrix(A, r1, c1);
    printf(">> Matrix B (%d x %d):\n", r2, c2);
    display_matrix(B, r2, c2);
    if (multiply_matrices(A, r1, c1, B, r2, c2, C))
    {
        printf(">> Result A x B (%d x %d):\n", r1, c2);
        display_matrix(C, r1, c2);
    }
    printf(">> \n");
    printf(">> Trying to multiply A x A (not possible, 3 != 2)...\n");
    multiply_matrices(A, r1, c1, A, r1, c1, C);
    printf("\n\n");

    printf("TASK 2: Multiplication of two arrays (element-wise)\n");
    printf("-------\n");
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {10, 20, 30, 40, 50};
    int result[5];
    int n = 5;
    multiply_arrays(arr1, arr2, result, n);
    printf(">> Array 1: ");
    for (int i = 0; i < n; i++) printf("%d ", arr1[i]);
    printf("\n>> Array 2: ");
    for (int i = 0; i < n; i++) printf("%d ", arr2[i]);
    printf("\n>> Product: ");
    for (int i = 0; i < n; i++) printf("%d ", result[i]);
    printf("\n\n\n");

    return 0;
}
