#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(Node* root, int data)
{
    if (root == NULL)
	{
        root = createNode(data);
        return root;
    }
    else if (data <= root->data)
	{
        root->left = insertNode(root->left, data);
    }
    else
	{
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inorderTraversal(Node* root)
{
    if (root == NULL)
	{
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root)
{
    if (root == NULL)
	{
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root)
{
    if (root == NULL)
	{
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

void displayTree(Node* root)
{
    if (root == NULL) 
	{
		printf("\nTree is empty. No elements to display.");
        return;
    }
    int ch;
    printf("\n Menu for Displaying the Tree : \n");
    printf("1. Inorder Traversal\n");
    printf("2. Preorder Traversal\n");
    printf("3. Postorder Traversal\n");
    printf("Enter your choice : \n");
    scanf("%d",&ch);
    
    
    switch(ch)
		{
			case 1:
				printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
			case 2:
				printf("Preorder Traversal: ");
	            preorderTraversal(root);
	            printf("\n");
	            break;
			case 3:
				printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
			default:
				printf("Invalid choice. Please retry.");				
		}
}
int main()
{
    Node* root = NULL;
    int choice, data;
    printf("\n Binary Tree Creation and Traversal");
    do {
    	printf("\n---------MAIN MENU---------\n");
        printf(" 1. Create Tree / Insert Node  \n");
        printf(" 2. Display Tree \n");
        printf(" 3. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

	        switch (choice)
			{
	            case 1:
	                printf("Enter data to be inserted: ");
	                scanf("%d", &data);
	                root = insertNode(root, data);
	                printf("Node inserted.\n");
	                break;
	            case 2:
	                displayTree(root);
					break;
	            case 3:
	                printf("Exiting...\n");
	                break;
	            default:
	                printf("Invalid choice! Please try again.\n");
	        }
    	} while (choice != 3);
    return 0;
}
