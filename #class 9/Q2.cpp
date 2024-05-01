//2. WAP to implement a queue using stack data structure. 

#include <stdio.h> 
#include <stdlib.h> 
#define MAX_SIZE 100 
struct Stack { 
int items[MAX_SIZE]; 
int top; 
}; 
typedef struct Stack Stack; 
void initialize(Stack* stack) { 
stack->top = -1; 
} 
int is_empty(Stack* stack) { 
return stack->top == -1; 
} 
int is_full(Stack* stack) { 
return stack->top == MAX_SIZE - 1; 
} 
void push(Stack* stack, int value) { 
if (!is_full(stack)) { 
stack->items[++stack->top] = value; 
} else { 
printf("Stack overflow\n"); 
} 
} 
int pop(Stack* stack) { 
if (!is_empty(stack)) { 
return stack->items[stack->top--];} else { 
printf("Stack is empty\n"); 
return -1; 
} 
} 
void enqueue(Stack* stack1, int value) { 
push(stack1, value); 
} 
int dequeue(Stack* stack1, Stack* stack2) { 
if (is_empty(stack2)) { 
while (!is_empty(stack1)) { 
push(stack2, pop(stack1)); 
} 
} 
if (!is_empty(stack2)) { 
return pop(stack2); 
} else { 
printf("Queue is empty\n"); 
return -1; 
} 
} 
int main() { 
Stack stack1, stack2; 
initialize(&stack1); 
initialize(&stack2); 
int choice, data; 
while (1) { 
printf("\nMenu:\n"); 
printf("1. Enqueue\n"); 
printf("2. Dequeue\n"); 
printf("3. Exit\n"); 
printf("Enter your choice: "); 
scanf("%d", &choice); 
switch (choice) { 
case 1: 
printf("Enter the element to enqueue: "); 
scanf("%d", &data); 
enqueue(&stack1, data); 
break; 
case 2: 
data = dequeue(&stack1, &stack2); 
if (data != -1) { 
printf("Dequeued: %d\n", data); 
} 
break; 
case 3: 
printf("Exiting the program.\n"); 
exit(0); 
default:printf("Invalid choice. Please select a valid option.\n"); 
} 
} 
return 0; 
}