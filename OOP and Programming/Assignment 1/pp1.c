#include<stdio.h>
int main()
{
	int num;
	int* p;
	int** pp;
	printf("Enter the variable : ");
	scanf("%d", &num);
	p = &num;
	pp = &p;
	printf("The number using p is %d \n", *p);
	printf("The number using pp is %d \n", **pp);
	}
