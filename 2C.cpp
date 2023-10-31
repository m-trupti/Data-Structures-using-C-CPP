#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
    struct Node  *head=NULL, *current;

// Function to append a new node to the end of the list
void append(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) 
	{
        head = newNode;
    } 
	else 
	{
        current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}


// Function to display the contents of the list
void display() {
    current = head;
    if(current==NULL)
    {
    	printf("The Linked list is empty. No elements to display.");
	}
		printf("The Linked List is : ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to swap two nodes
void swapNodes(struct Node* node1, struct Node* node2) {
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

// Function to sort the list using bubble sort
void bubbleSort() {
    if (head == NULL || head->next == NULL) 
	{
        printf("List is empty or has only one element, no need to sort");
    }

    int swapped;
    struct Node* current;
    struct Node* last = NULL;

    do {
        swapped = 0;
        current = head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                swapNodes(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

int main()
{
	int opt,val;
	do
	{
		printf("\n*****  MAIN MENU  *****\n");
		printf("1. Create a List : \n");
		printf("2. Display List : \n");
		printf("3. Sort List : \n");
		printf("4. Exit : \n");
		printf("5. Enter your choice : \n");
		scanf("%d",&opt);
		printf("\n");
		switch(opt)
		{
			case 1:
			while(val!=-1)
			{
			 printf("Enter the data or enter -1 to exit : ");
			 scanf("%d",&val);
			 append(val);
			};
			break;
			case 2: 
			display();
			break;
			case 3: 
			{	
			printf("After Sorting : ");
			bubbleSort();
			display();
			}
			break;
			case 4: break;
		}
	}while(opt!=4);
	
    return 0;
}
