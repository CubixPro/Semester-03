#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void malloc_names(char *** names, int num)
{
	char **name = (char **)malloc(num * sizeof(char *));
	for(int i = 0 ; i < num ; i++)
	{
		name[i] = (char *)malloc(1000 *  sizeof(char));
	}
	*names = name;
}
void malloc_ages(int **ages, int num)
{
	int *age = (int *)malloc(num * sizeof(int));
	*ages = age;
}

void sort(char ***names, int **ages, int num)
{
	char **name = (char **)malloc(num * sizeof(char *));
	for(int i = 0 ; i < num ; i++)
	{
		name[i] = (char *)malloc(1000 *  sizeof(char));
	}
	int *age  = (int *)malloc(num * sizeof(int));
	name = *names;
	age = *ages;
	for(int i = 0 ; i < num - 1 ; i ++)
	{
		for(int j = 0 ; j < num - i - 1; j++)
		{
			if(age[j] > age[j + 1])
			{
				int temp = age[j];
				age[j] = age[j + 1];
				age[j + 1] = temp;
				char emp[1000];
				strcpy(emp, name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], emp);
			}
		}
	}
}

int main()
{
	printf("Enter the number of people : ");
	int num;
	scanf("%d", &num);
	char **names ;/*= (char **)malloc(num * sizeof(char *));
	for(int i = 0 ; i < num ; i++)
	{
		names[i] = (char *)malloc(1000 *  sizeof(char));
	}*/
	malloc_names(&names, num);
	int *ages;  /*= (int *)malloc(num * sizeof(int));*/
	malloc_ages(&ages, num);
	for(int i = 0  ; i < num ; i++)
	{
		printf("Name of student %d : ", i + 1);
		char c = getchar();
		while(c!='\n' && c!=EOF)
			c = getchar();
		fgets(names[i], 1000, stdin);
		printf("Age of student %d : ", i + 1);
		scanf("%d", &ages[i]);
	}
	/*for(int i = 0  ; i < num ; i++)
	{
		printf("Name of student %d : %s", i + 1, names[i]);
		
		printf("Age of student %d : %d\n", i + 1, ages[i]);
		
	}*/
	sort(&names, &ages, num);
	for(int i = 0 ;  i < num ; i ++)
	{
		printf("Name : %sAge : %d\n", names[i], ages[i]);
	}
}
	
	
	
	
	
	
	
	

