/*
Problem: In a country X, all the ants move in a circle. There is a circle marked with N marks with numbers from 1 to N clockwise. There are M ants on the circle. No two ants stand on the same mark intially. It is also known in which direction each ant will move. If two ants meet during the movement, then each of them begins to move in a different direction. Your task is to determine where the ants will be after T seconds of such movement.
Input Format: 
- The first line contains numbers N, M, T.
- The following M lines have the following format:
    - Each line contains two numbers x and y. The first number of this line x is the position of the ant, the second number of this line y is the direction in which the ant moves.
    - y = 1, if ant moves clockwise. y = -1 if counterclockwise.
    - The distance between the adjacent marks the same.
    - In 1 second, the ant overcomes a distance equal to the distance between adjacent marks on the circle.
*/

#include <stdio.h>
#include <stdlib.h>


struct Ant {
    int position;
    int direction;
};


int main()
{
    int N = 0, M = 0, T = 0;
    printf("----------\n");
    do
    {
        printf("Number of Marks: ");
        scanf("%d", &N);
    } while (N <= 0);
    do
    {
        printf("Number of Ants: ");
        scanf("%d", &M);
    } while (M < 0 || M > N);
    do
    {
        printf("Time (seconds): ");
        scanf("%d", &T);
    } while (T < 0);
    printf("\n");

    struct Ant ants[M];
    for (int i = 0; i < M; i++)
    {
        do
        {
            printf(">> Position of Ant %d: ", i + 1);
            scanf("%d", &ants[i].position);
        } while (ants[i].position <= 0 || ants[i].position > N);
        do
        {
            printf(">> Direction of Ant %d: ", i + 1);
            scanf("%d", &ants[i].direction);
        } while (ants[i].direction != 1 && ants[i].direction != -1);
        printf("\n");
    }
    printf("----------\n");

    for (int t = 0; t < T; t++)
    {
        for (int i = 0; i < M; i++)
        {
            ants[i].position += ants[i].direction;
            if (ants[i].position > N)
            {
                ants[i].position = 1;
            }
            if (ants[i].position < 1)
            {
                ants[i].position = N;
            }
        }

        // Comparing each ant position for collision
        for (int i = 0; i < M - 1; i++)
        {
            if (ants[i].position == ants[i + 1].position)
            {
                ants[i].direction *= -1;
                ants[i + 1].direction *= -1;
            }
        }
    }

    printf("Position of ants after %d seconds: \n", T);
    for (int i = 0; i < M; i++)
    {
        printf(">> Position of Ant %d: ", i + 1);
        printf("%d \n", ants[i].position);
    }
    printf("----------\n");
}