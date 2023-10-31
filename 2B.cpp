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
struct node *searchll(struct node*);
int main()
{
	int opt;
	do
	{
		printf("\n*****  MAIN MENU  *****\n");
		printf("1. Create a List : \n");
		printf("2. Display List : \n");
		printf("3. Search : \n");
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
			case 3: searchll(start);
			break;
			case 4: break;
		}
	}while(opt!=4);
	return 0;
}
struct node *searchll(struct node *start)
{
	int val,count,x=0;
	struct node *temp;
	printf("Which value are you looking for ? \n");
	scanf("%d",&val);
	count=1;
	temp=start;
	while(temp->data!=val && temp->next!=NULL)
	{
		temp=temp->next;
		count++;
	}
	if(temp->next==NULL && temp->data!=val)
	{
		printf("Value not found.");
	}
	else if(temp->next==NULL && temp->data==val)
	{
		printf("Value found at %d node \n ",count);
	}
	else
	{
		printf("Value found at %d node ",count);
	}
	return start;
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
	if(temp==NULL)
	{
		printf("The linked list is empty.");
	}
	else
	{
		printf("The Linked List is : ");
	while(temp!=NULL)
	{
		printf("\t %d",temp->data);
		temp=temp->next;
	}
}
	printf("\n");
	return start;
}
