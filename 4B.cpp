#include <stdio.h>
using namespace std;
#define MAX_SIZE 5

int front = -1;
int rear = -1;
int queue[MAX_SIZE];

int isFull()
{
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1)))
	{
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (front == -1)
	{
        return 1;
    }
    return 0;
}

void enqueue(int item)
{
    if (isFull())
	{
        printf("Queue is full. Unable to enqueue element. \n");
    }
	else
	{
        if (front == -1)
		{
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = item;
        printf("Enqueued element: %d \n", item);
    }
}

void dequeue()
{
    if (isEmpty())
	{
        printf("Queue is empty. Unable to dequeue element. \n");
    }
	else
	{
        int item = queue[front];
        if (front == rear)
		{
            front = -1;
            rear = -1;
        }
		else
		{
            front = (front + 1) % MAX_SIZE;
        }
        printf("Dequeued element: %d \n", item);
    }
}

void display()
{
    if (isEmpty()) 
	{
        printf("Queue is empty. Nothing to display. \n");
    } 
	else
	{
        printf("Elements in the queue: ");
        int i = front;
        if (front <= rear)
		{
            while (i <= rear)
			{
                printf("%d ", queue[i]);
                i++;
            }
        }
		else
		{
            while (i <= MAX_SIZE - 1)
			{
                printf("%d ", queue[i]);
                i++;
            }
            i = 0;
            while (i <= rear)
			{
                printf("%d ", queue[i]);
                i++;
            }
        }
        printf("\n");
    }
}

int main()
{
int choice,item;
do
{
	printf("\n ---MAIN MENU--- \n");
	printf("1.Insert \n");
	printf("2.Delete \n");
	printf("3.Display \n");
	printf("4.Quit \n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	switch(choice)
{
	case 1 :
	printf("Input the element for insertion in queue : ");
	scanf("%d", &item);
	enqueue(item);
	break;
	case 2 :
	dequeue();
	break;
	case 3:
	display();
	break;
	case 4:
	break;
	default:
	printf("Wrong choice \n");
}
}while(choice!=4);
return 0;
}
