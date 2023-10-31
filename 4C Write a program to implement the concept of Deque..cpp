#include<stdio.h>
#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;
void enqueue(int element)
{
	if((rear+1)%MAX==front)
	{
		printf("Queue is full");
	}
	else if(front==-1&&rear==-1)
	{
		front=0;
		rear=0;
		queue[rear]=element;
		printf("\n Inserted at %d ",rear);
	}
	else
	{
	    rear=(rear+1)%MAX;
	    queue[rear]=element;
	    printf("\n Inserted at %d ",rear);
	}
}
int dequeue()
{
	if((front==-1)&&(rear==-1))
	{
		printf("Queue is underflow..");
	}
	else if(front==rear)
	{
		printf("\n The dequeue element is %d",queue[front]);
		printf("\t Deleted from %d",front);
		front=-1;
		rear=-1;
	}
	else
	{
		printf("\n The dequeue element is %d",queue[front]);
		printf("\t Deleted from %d",front);
		front=(front+1)%MAX;
	}
}
void enqueueatfront(int element)
{
	if((front-1)%MAX==rear)
	{
		printf("Queue is full");
	}
	else if(front==-1&&rear==-1)
	{
		front=0;
		rear=0;
		queue[front]=element;
		printf("\n Inserted at %d ",front);
	}
	else
	{
	    front=(front-1)%MAX;
	    queue[front]=element;
	    printf("\n Inserted at %d ",front);
	}
}
int dequeueatrear()
{
	if((front==-1)&&(rear==-1))
	{
		printf("Queue is underflow..");
	}
	else if(front==rear)
	{
		printf("\n The dequeue element is %d",queue[rear]);
		printf("\t Deleted from %d",rear);
		front=-1;
		rear=-1;
	}
	else
	{
		printf("\n The dequeue element is %d",queue[rear]);
		printf("\t Deleted from %d",rear);
		rear--;
	}
}
void display()
{
	int i=front;
	if(front==-1&&rear==-1)
	{
		printf("\n Queue is empty..");
	}
	else
	{
	    printf("Elements in Queue are : ");
		for(i=0;i<front;i++)
		{
			printf("%d,",queue[i]);
		}
		for(i=front;i<=rear;i++)
		{
		    printf("%d,",queue[i]);	
		}	
	}
}
int main()
{
	int choice=1,x,x1;
	while(choice<11&&choice!=0)
	{
	printf("\n \n 1.Insert an element\n 2.Delete an element\n 3.Insert at front\n 4.Delete at rear\n 5.Display\n Enter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("Enter the element which is to be inserted : ");
			scanf("%d",&x);
			enqueue(x);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			printf("Enter the element which is to be inserted at front : ");
			scanf("%d",&x1);
			enqueueatfront(x1);
	    	break;
		case 4:
			dequeueatrear();
		    break;
		case 5:
			display();
			break;
		default:
			printf("\n Wrong selection !!! Try again !!!");
	}
    }
	return 0;
}
