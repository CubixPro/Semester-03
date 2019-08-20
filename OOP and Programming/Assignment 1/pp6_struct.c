#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int age;
	char name[1000];
} student;
void sort(student **stud, int num)
{
	
	student *people = (student*)malloc(num * sizeof(student));
	people = *stud;
	for(int i = 0 ; i < num - 1 ; i ++)
	{
		for(int j = 0 ; j < num - i - 1; j++)
		{
			if(people[j].age > people[j + 1].age)
			{
				student temp = people[j];
				people[j] = people[j + 1];
				people[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int num;
	printf("Enter the number of students : ");
	scanf("%d", &num);
	student* stud = (student *)malloc(num * sizeof(student));
	for(int i = 0 ; i < num ; i++)
	{
		printf("Name of student %d : ", i + 1);
		char c = getchar();
		while(c!='\n' && c!=EOF)
			c = getchar();
		fgets(stud[i].name, 1000, stdin);
		printf("Age : ");
		scanf("%d", &stud[i].age);
	}
	sort(&stud, num);
	for(int i = 0 ; i < num ;i++)
	{
		printf("%s ", stud[i].name);
		}
	
		
}
