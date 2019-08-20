#include<stdio.h>
#include<stdlib.h>

int main()
{
	int row, col;
	printf("Enter the row and columns : ");
	scanf("%d %d", &row, &col);
	int **p = (int**)malloc(row * sizeof(int*));
	for(int i = 0 ; i < row ; i++)
	{
		*(p + i) = (int *)malloc(col * sizeof(int));
	}
	for(int i = 0 ; i < row ; i++)
	{
		for(int j = 0 ; j < col ; j++)
		{
			printf("arr[%d][%d] : ", i, j);
			scanf("%d", (*(p + i) + j));
		}
	}
	for(int i = 0 ; i < row ; i++)
	{
		for(int j = 0 ; j < col ; j++)
		{
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}
	
}
	
