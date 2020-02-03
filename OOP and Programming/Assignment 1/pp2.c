#include<stdio.h>
#include<stdlib.h>
int main()
{
	int size;
	printf("Enter size of elements : ");
	scanf("%d", &size);
	int *p = (int *)malloc(size * sizeof(int));
	for(int i = 0 ; i < size ;  i++)
	{
		printf("arr[%d] : ", i);
		scanf("%d", p + i);
	}
	for(int i = 0 ; i < size ; i++)
	{
		printf("%d ", *( p + i));
	}
}
