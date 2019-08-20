#include <stdio.h>
#include <stdlib.h>

void allocate_2(int ***arr, int m, int n)
{
    int **p = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++)
    {
        p[i] = (int *)malloc(sizeof(int) * n);
    }
}
void initialize_2(int ***arr, int m, int n)
{
    int **p = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++)
    {
        p[i] = (int *)malloc(sizeof(int) * n);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", (*(p + i) + j));
        }
    }
    *arr = p;
}
void print_2(int **arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

void allocate_1(int **arr, int m)
{
    int *p = (int *)malloc(m * sizeof(int));
    *arr = p;
}

void initialize_1(int **arr, int m)
{
    for (int i = 0; i < m; i++)
    {
        scanf("%d", (*arr + i));
    }
}

void print_1(int arr[], int m)
{
    printf("The entered array is : ");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    printf("1. Create a one dimentional array\n2. Create a two dimentional array\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        int *arr;
        printf("Enter the number of elements : ");
        int m;
        scanf("%d", &m);
        allocate_1(&arr, m);
        initialize_1(&arr, m);
        print_1(arr, m);
        break;
    }
    case 2:
    {
        int **arr;
        printf("Enter the number of rows and columns : ");
        int m, n;
        scanf("%d %d", &m, &n);
        allocate_2(&arr, m, n);
        initialize_2(&arr, m, n);
        print_2(arr, m, n);
    }
    default:
        break;
    }
}