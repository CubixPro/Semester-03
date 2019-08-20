#include<stdio.h>
#include<stdlib.h>


typedef struct{
	int roll;
	char name[31];
	int score;
	struct student* next;
	} student;

void create(student** stud)
{
	student *p;
	p = (student *)malloc(sizeof(student));
	p->next = NULL;
	scanf("%d", &p->roll);
	scanf("%d", &p->score);
	char c = getchar();
		while(c!='\n' && c!=EOF)
			c = getchar();
	fgets(p->name, 31, stdin);
	//scanf("%[^\n]", p->name);
	*stud = p;
}
void display(student *p)
{
	while(p->next != NULL)	
	{
		printf("Name : %sRoll : %d\nScore : %d\n", p->name, p->roll, p->score);
		p = (p->next);
		printf("-----------------------------------\n");
	}
	printf("Name : %sRoll : %d\nScore : %d\n", p->name, p->roll, p->score);printf("-----------------------------------\n");
	
}
void append(student *node)
{
	 student *p;
	 p = (student *)malloc(sizeof(student));
	 create(&p);
	 while(node->next != NULL)
	 {
	 	node = node->next;
	 }
	 node->next = p;
}
void insert_before(student** node, int n)
{
	student *p = (student*)malloc(sizeof(student));
	create(&p);
	student *prev, *curr;
	prev = (student *)malloc(sizeof(student));
	curr = (student *)malloc(sizeof(student));
	curr = *node;
	if(curr->roll == n)
	{
		p->next = curr;
		*node = p;
	}
	else
	{
		prev = curr;
		curr = (*node)->next;
		while(curr != NULL)
		{
			if(curr->roll == n)
				break;
			prev = curr;
			curr = curr->next;
		}
		if(curr == NULL)
		{
			printf("Target not found\n");
		}
		else
		{
			p->next = prev->next;
			prev->next = p;
		}
	}
}
void delete(student **node, int roll)
{
	student* p, *prev, *curr;
	p = (student *)malloc(sizeof(student));
	prev = (student *)malloc(sizeof(student));
	curr = (student *)malloc(sizeof(student));
	curr = *node;
	if(curr->roll == roll)
	{
		*node = (*node)->next;
		free(curr);
	}
	else
	{
		while(curr->next != NULL)
		{
			if(curr->roll == roll)
				break;
			prev = curr;
			curr = curr->next;
		}
		if(curr == NULL)
		{
			printf("Target not found \n");
			return;
		}
		prev->next = curr->next;
		free(curr);
	}
}
	int main()
{
		student *head;
		printf("Enter your option\n\t1. Create\n\t2. Append\n\t3. Display\n\t4. Insert before a particular roll number\n\t5. Delete a particular roll number\n");
		int ch;
		
		scanf("%d", &ch);
		//printf("%c", ch);
		while(ch != -1)
		{
			switch(ch)
			{
				case 1: if(head != NULL)
						printf("Exists\n");
					else
					{
						create(&head);
					}
					//printf("%s", head->name);
					break;
				case 3: if(head!=NULL)
							display(head);
						else
							printf("First create the list\n");
						break;
				case 2: if(head != NULL)
							append(head);
						 else
						 	printf("List does not exist\n");
						 break;
				case 4: if(head != NULL)
							{
								printf("Enter the roll number you want to insert before : ");
								int rolls;
								scanf("%d", &rolls);
								insert_before(&head, rolls);
							}
						else
							printf("List doesn't exist");
						break;
				case 5: if(head != NULL)
						{
							printf("Enter the roll number you want to delete : ");
							int rolls ; 
							scanf("%d", &rolls);
							delete(&head, rolls);
						}
				default : printf("Excuse me!");
			}
			printf("Enter your option\n\t1. Create\n\t2. Append\n\t3. Display\n\t4. Insert before a particular roll number\n\t5. Delete a particular roll number\n");
			
			//printf("Name : %sRoll : %d\nScore : %d\n", p.name, p.roll, p.score);
			scanf("%d", &ch);
		}	
}
		


		
