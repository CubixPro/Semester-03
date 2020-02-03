#include<stdio.h>
#include<stdlib.h>


int main()
{
	
	int row;
	scanf("%d", &row);
	int col = 3;
	int (*p)[col];
	p = (int **)malloc(row * col * sizeof(int));
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
	
	

	
