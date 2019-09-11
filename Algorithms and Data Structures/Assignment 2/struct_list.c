#include<stdio.h>

typedef struct node{
    int element;
    node* next;

};
void init_l(node** curr)
{
   *curr = (node *)malloc(sizeof(node));
}

int empty_l(node *head)//1 is true 0 is false
{
    if(*head == null)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int at_end(node *curr)
{
    if(curr->next == null)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void insert_front(node* target, node **head)
{
    node* newhead = (node *)malloc(sizeof(node));
    newhead = *head;
    target->next = newhead;
    *head = target;
}
void insert_after(node* target, node *prev)
{
    node* newhead = (node *)malloc(sizeof(node));
    newhead = prev->next;
    prev->next = target;
    target->next = newhead;
}
void delete_front(node **head)
{
    node* newhead = (node *)malloc(sizeof(node));
    newhead = *head;
    *head = *head->next;
    free(newhead);

}
void delete_after(node* prev)
{
    prev = prev->next;
}

