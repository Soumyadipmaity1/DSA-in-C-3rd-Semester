/*1. Write a menu driven program to perform the following 
operations of a stack using array by using suitable user 
defined functions for each case. 
a) Check if the stack is empty 
b) Display the contents of stack 
c) Push 
d) Pop  */


#include <stdio.h> 
#include <stdlib.h> 
#defineMAX_SIZE10 
struct Stack { 
 int items[MAX_SIZE]; 
 int top; 
}; 
void initialize(struct Stack *stack) { 
 stack->top = -1; 
} 
int isEmpty(struct Stack *stack) { 
 return stack->top == -1; 
} 
int isFull(struct Stack *stack) { 
 return stack->top == MAX_SIZE - 1; 
} 
void push(struct Stack *stack, int value) { 
 if (isFull(stack)) { 
 printf("Stack is full. Cannot push %d.\n", value); 
 } else { 
 stack->top++; 
 stack->items[stack->top] = value; 
 printf("Pushed %d onto the stack.\n", value); 
 } 
} 
void pop(struct Stack *stack) { 
 if (isEmpty(stack)) { 
 printf("Stack is empty. Cannot pop.\n"); 
 } else { 
 int poppedValue = stack->items[stack->top]; 
 stack->top--; 
 printf("Popped %d from the stack.\n", poppedValue); 
 } 
} 
void display(struct Stack *stack) { 
 if (isEmpty(stack)) { 
 printf("Stack is empty.\n"); 
 } else { 
 printf("Stack contents:\n"); 
 for (int i = 0; i <= stack->top; i++) { 
 printf("%d ", stack->items[i]); 
 } 
 printf("\n"); 
 } 
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