#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// Function to check if the stack is empty
bool isStackEmpty(int top) 
{
    return top == -1;
}

// Function to check if the stack is full
bool isStackFull(int top) 
{
    return top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(char stack[], int* top, char value) 
{
    if (!isStackFull(*top)) 
	{
        stack[++(*top)] = value;
    } else 
	{
        printf("Error: Stack is full.\n");
    }
}

// Function to pop an element from the stack
char pop(char stack[], int* top) 
{
    if (!isStackEmpty(*top)) 
	{
        return stack[(*top)--];
    } else 
	{
        printf("Error: Stack is empty.\n");
        return '\0';
    }
}

// Function to get the precedence of an operator
int precedence(char operators) 
{
    switch (operators) 
	{
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to check if a character is an operator
bool isOperator(char ch) 
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to check if a character is an operand (letter or digit)
bool isOperand(char ch) 
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}

// Function to reverse a string in place
void reverseString(char* str) 
{
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; ++i, --j) 
	{
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to convert infix expression to postfix expression
void infixToPostfix(const char* infix, char* postfix) 
{
    char operatorStack[MAX_SIZE];
    int operatorTop = -1;
    int postfixIndex = 0;

    for (int i = 0; infix[i] != '\0'; ++i) 
	{
        char current = infix[i];

        if (isOperand(current)) 
		{
            postfix[postfixIndex++] = current;
        } 
		else if (isOperator(current)) 
		{
            while (!isStackEmpty(operatorTop) && precedence(operatorStack[operatorTop]) >= precedence(current)) 
			{
                postfix[postfixIndex++] = pop(operatorStack, &operatorTop);
            }
            push(operatorStack, &operatorTop, current);
        } 
		else if (current == '(') 
		{
            push(operatorStack, &operatorTop, current);
        } 
		else if (current == ')') 
		{
            while (!isStackEmpty(operatorTop) && operatorStack[operatorTop] != '(') 
			{
                postfix[postfixIndex++] = pop(operatorStack, &operatorTop);
            }
            pop(operatorStack, &operatorTop); // Discard the open parenthesis '('
        }
    }
    
    // Pop remaining operators from the stack
    while (!isStackEmpty(operatorTop)) {
        postfix[postfixIndex++] = pop(operatorStack, &operatorTop);
    }

    postfix[postfixIndex] = '\0'; // Null-terminate the postfix string
}

// Function to convert infix expression to prefix expression
void infixToPrefix(const char* infix, char* prefix) {
    char operatorStack[MAX_SIZE];
    int operatorTop = -1;
    int prefixIndex = 0;

    // Reverse the infix expression
    char reversedInfix[MAX_SIZE];
    strcpy(reversedInfix, infix);
    reverseString(reversedInfix);

    for (int i = 0; reversedInfix[i] != '\0'; ++i) {
        char current = reversedInfix[i];

        if (isOperand(current)) {
            prefix[prefixIndex++] = current;
        } else if (isOperator(current)) {
            while (!isStackEmpty(operatorTop) && precedence(operatorStack[operatorTop]) > precedence(current)) {
                prefix[prefixIndex++] = pop(operatorStack, &operatorTop);
            }
            push(operatorStack, &operatorTop, current);
        } else if (current == ')') {
            push(operatorStack, &operatorTop, current);
        } else if (current == '(') {
            while (!isStackEmpty(operatorTop) && operatorStack[operatorTop] != ')') {
                prefix[prefixIndex++] = pop(operatorStack, &operatorTop);
            }
            pop(operatorStack, &operatorTop); // Discard the closing parenthesis ')'
        }
    }

    // Pop remaining operators from the stack
    while (!isStackEmpty(operatorTop)) {
        prefix[prefixIndex++] = pop(operatorStack, &operatorTop);
    }

    prefix[prefixIndex] = '\0'; // Null-terminate the prefix string
    reverseString(prefix);      // Reverse the prefix expression to get the final result
}

int main() 
{
    char infixExpression[MAX_SIZE];
    char postfixExpression[MAX_SIZE];
    char prefixExpression[MAX_SIZE];
	int ch=1;
	
    printf("Enter an infix expression: ");
    scanf("%s", infixExpression);

	while(ch)
	{
		printf("Select your Operation\n1. Infix to Postfix\n2. Infix to Prefix\n3. Exit\n\n");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1: 
				 infixToPostfix(infixExpression, postfixExpression);
    			 printf("Postfix expression: %s\n", postfixExpression);
    			 break;
    		case 2:
			    infixToPrefix(infixExpression, prefixExpression);
			    printf("Prefix expression: %s\n", prefixExpression);
			    break;
    		case 3:
    			exit(0);
    			break;
    		default:
    			return 0;
		}
	}
	
    
   

    return 0;
}

