#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *create(struct node*);
struct node *display(struct node*);
void reverse(struct node*);
struct node *deletell(struct node*);
int main()
{
	int opt;
	do
	{
		printf("\n*****  MAIN MENU  *****\n");
		printf("1. Create a List : \n");
		printf("2. Display List : \n");
		printf("3. Reverse List : \n");
		printf("4. Exit : \n");
		printf("5. Enter your choice : \n");
		scanf("%d",&opt);
		printf("\n");
		switch(opt)
		{
			case 1: start=create(start);
			break;
			case 2: start=display(start);
			break;
			case 3: reverse(start);
			break;
			case 4: break;
		}
	}while(opt!=4);
	return 0;
}
void reverse(struct node *head)
{
	struct node* prev=NULL;
	struct node* current=head;
	struct node* next;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
	head=display(head);
}
struct node *create(struct node *start)
{
	struct node *new_node=NULL,*temp=NULL;
	int val;
	printf("Enter the data or enter -1 to exit : ");
	scanf("%d",&val);
	while(val!=-1)
	{
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=val;
		if(start==NULL)
		{
			start=new_node;
			new_node->next=NULL;
		}
		else
		{
			temp=start;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=new_node;
			new_node->next=NULL;
		}
		printf("Enter the data or enter -1 to exit : ");
		scanf("%d",&val);
	}
	printf("Linked list created successfully. \n");
	return start;
}
struct node *display(struct node *start)
{
	struct node *temp=NULL;
	temp=start;
	printf("The Linked List is : ");
	while(temp!=NULL)
	{
		printf("\t %d",temp->data);
		temp=temp->next;
	}
	printf("\n");
	return start;
}

