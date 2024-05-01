// 4. WAP to reverse a stack with using extra stack.
#include <stdio.h> 
#include <stdlib.h> 
struct Stack { 
 int data; 
 struct Stack* next; 
}; 
void initialize(struct Stack** stack) { 
 *stack = NULL; 
} 
int isEmpty(struct Stack* stack) { 
 return stack == NULL; 
} 
void push(struct Stack** stack, int value) { 
 struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack)); 
 if (newNode == NULL) { 
 printf("Memory allocation failed. Cannot push %d.\n", value); 
 exit(1); 
 } 
 newNode->data = value; 
 newNode->next = *stack; 
 *stack = newNode; 
} 
int pop(struct Stack** stack) { 
 if (isEmpty(*stack)) { 
 printf("Stack is empty. Cannot pop.\n"); 
 exit(1); 
 } 
 int value = (*stack)->data; 
 struct Stack* temp = *stack; 
 *stack = (*stack)->next; 
 free(temp); 
 return value; 
} 
void display(struct Stack* stack) { 
 struct Stack* current = stack; 
 while (current != NULL) { 
 printf("%d ", current->data); 
 current = current->next; 
 } 
 printf("\n"); 
} 
void reverseStack(struct Stack** originalStack) { 
 struct Stack* reversedStack = NULL; 
 while (!isEmpty(*originalStack)) { 
 int value = pop(originalStack); 
 push(&reversedStack, value); 
 } 
 *originalStack = reversedStack; 
} 
int main() { 
 struct Stack* stack; 
 initialize(&stack); 
 push(&stack, 1); 
 push(&stack, 2); 
 push(&stack, 3); 
 push(&stack, 4); 
 printf("Original Stack: "); 
 display(stack); 
 reverseStack(&stack); 
 printf("Reversed Stack: "); 
 display(stack); 
 return 0; 
} 