/*2. Write a menu driven program to perform the following 
operations of a stack using linked list by using suitable user 
defined functions for each case. 
a) Check if the stack is empty 
b) Display the contents of stack 
c) Push 
d) Pop */
#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
 int data; 
 struct Node* next; 
}; 
struct Stack { 
 struct Node* top; 
}; 
void initialize(struct Stack* stack) { 
 stack->top = NULL; 
} 
int isEmpty(struct Stack* stack) { 
 return stack->top == NULL; 
} 
void push(struct Stack* stack, int value) { 
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
 if (newNode == NULL) { 
 printf("Memory allocation failed. Cannot push %d.\n", value); 
 return; 
 } 
 newNode->data = value; 
 newNode->next = stack->top; 
 stack->top = newNode; 
 printf("Pushed %d onto the stack.\n", value); 
} 
void pop(struct Stack* stack) { 
 if (isEmpty(stack)) { 
 printf("Stack is empty. Cannot pop.\n"); 
 return; 
 } 
 struct Node* poppedNode = stack->top; 
 stack->top = stack->top->next; 
 int poppedValue = poppedNode->data; 
 free(poppedNode); 
 printf("Popped %d from the stack.\n", poppedValue); 
} 
void display(struct Stack* stack) { 
 if (isEmpty(stack)) { 
 printf("Stack is empty.\n"); 
 return; 
 } 
 printf("Stack contents:\n"); 
 struct Node* current = stack->top; 
 while (current != NULL) { 
 printf("%d ", current->data); 
 current = current->next; 
 } 
 printf("\n"); 
} 
int main() { 
 struct Stack stack; 
 initialize(&stack); 
 int choice, value; 
 while (1) { 
 printf("\nStack Menu:\n"); 
 printf("1. Check if the stack is empty\n"); 
 printf("2. Display the contents of stack\n"); 
 printf("3. Push an element onto the stack\n"); 
 printf("4. Pop an element from the stack\n"); 
 printf("5. Exit\n"); 
 printf("Enter your choice: "); 
 scanf("%d", &choice); 
 switch (choice) { 
 case 1: 
 if (isEmpty(&stack)) { 
 printf("Stack is empty.\n"); 
 } else { 
 printf("Stack is not empty.\n"); 
 } 
 break; 
 case 2: 
 display(&stack); 
 break; 
 case 3: 
 printf("Enter the value to push: "); 
 scanf("%d", &value); 
 push(&stack, value); 
 break; 
 case 4: 
 pop(&stack); 
 break; 
 case 5: 
 printf("Exiting the program.\n"); 
 exit(0); 
 default: 
 printf("Invalid choice. Please try again.\n"); 
 } 
 } 
 return 0; 
} 