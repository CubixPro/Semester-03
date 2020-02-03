#include<iostream>
#include<stdio.h>
#define null NULL
class Node
{
	public:
	int val;
	Node* next;
	Node(int v)
	{
		val = v;
		next = null;
	}
	friend class LinkedList;
};

class LinkedList
{
	public:
	Node* head;
	
	LinkedList()
	{
		head = NULL; 
	}

	void append(int ele)
	{
		Node *np = new Node(ele);
		if(head == null)
		{
			head = np;
		}
		else
		{
			Node* p = head;
			while(p->next != null)
			{
				p = p->next;
			}
			p->next = np;

		}
		

	}//end of append()

	void displayList()
	{
		Node *p = head;
		if(head == null)
		{
			printf("Empty List\n");
			return;
		}
		while(p->next != null)
		{
			printf("%d ", p->val);
			p = p->next;
		}
		printf("%d \n", p->val);
	}	//end of  displayList()

	void insertBefore(int cur_ele, int new_val)
	{
		Node *np = new Node(new_val);
		if(head->val == cur_ele)
		{
			np->next = head;
			head = np;
		}
		else
		{
			Node* curr = head->next;
			Node* prev = head;
			while(curr != null)
			{
				if(curr->val == cur_ele)
				{
					break;
				}
				curr = curr->next;
				prev = prev->next;
			}
			if(curr != null)
			{
				prev->next = np;
				np->next = curr;
			}
			else
			{
				printf("Element not found\n");
			}
			
		}
		
	}//end of insertBefore()

	void deleteElement(int ele)
	{
		if(head->val == ele)
		{
			Node* p = head;
			head = head->next;
			delete(p);
		}
		else
		{
			Node* curr = head->next;
			Node* prev = head;
			while(curr != null)
			{
				if(curr->val == ele)
					break;
				curr = curr->next;
				prev = prev->next;
			}
			if(curr == null)
			{
				printf("Element not found\n");
			}
			else
			{
				
				Node* fn = curr->next;
				delete(curr);				
				prev->next = fn;
			}
			
		}
		
	}
};



/*int main()
{
	LinkedList l1;
	//l1.displayList();
	l1.append(4);
	//l1.displayList();
	l1.append(7);
	//l1.displayList();
	l1.append(8);
	l1.append(9);
	l1.insertBefore(8, 1);
	l1.displayList();
	l1.insertBefore(10, 2);
	l1.deleteElement(10);
	l1.displayList();	
}*/