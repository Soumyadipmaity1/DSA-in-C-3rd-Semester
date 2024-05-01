//3. WAP using a function to reverse a queue by using stack. 


#include <stdio.h> 
#include <stdlib.h> 
#define MAX_SIZE 100 
struct Node { 
 int data; 
 struct Node* next; 
}; 
struct Queue { 
 struct Node* front; 
 struct Node* rear; 
}; 
void initializeQueue(struct Queue* queue) { 
 queue->front = NULL; 
 queue->rear = NULL; 
} 
int isQueueEmpty(struct Queue* queue) { 
 return (queue->front == NULL); 
} 
void enqueue(struct Queue* queue, int data) { 
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
 newNode->data = data; 
 newNode->next = NULL; 
 if (isQueueEmpty(queue)) { 
 queue->front = newNode; 
 queue->rear = newNode; 
 } else { 
 queue->rear->next = newNode; 
 queue->rear = newNode; 
 } 
} 
int dequeue(struct Queue* queue) { 
 if (isQueueEmpty(queue)) { 
 printf("Queue is empty. Cannot dequeue.\n"); 
 return -1; 
 } 
 int data = queue->front->data; 
 struct Node* temp = queue->front; 
 queue->front = queue->front->next; 
 free(temp); 
 if (queue->front == NULL) { 
 queue->rear = NULL; 
 } 
 return data; 
} 
struct Stack { 
 int arr[MAX_SIZE]; 
 int top; 
}; 
void initializeStack(struct Stack* stack) { 
 stack->top = -1; 
} 
int isStackEmpty(struct Stack* stack) { 
 return (stack->top == -1); 
} 
void push(struct Stack* stack, int data) { 
 if (stack->top == MAX_SIZE - 1) { 
 printf("Stack is full. Cannot push.\n"); 
 return; 
 } 
 stack->arr[++(stack->top)] = data; 
} 
int pop(struct Stack* stack) { 
 if (isStackEmpty(stack)) { 
 printf("Stack is empty. Cannot pop.\n"); 
 return -1; 
 } 
 return stack->arr[(stack->top)--]; 
} 
void reverseQueue(struct Queue* queue) { 
 struct Stack stack; 
 initializeStack(&stack); 
 while (!isQueueEmpty(queue)) { 
 int data = dequeue(queue); 
 push(&stack, data); 
 } 
 while (!isStackEmpty(&stack)) { 
 int data = pop(&stack); 
 enqueue(queue, data); 
 } 
} 
void display(struct Queue* queue) { 
 if (isQueueEmpty(queue)) { 
 printf("Queue is empty.\n"); 
 return; 
 } 
 struct Node* current = queue->front; 
 printf("Queue elements: "); 
 while (current != NULL) { 
 printf("%d ", current->data); 
 current = current->next; 
 } 
 printf("\n"); 
} 
int main() { 
 struct Queue queue; 
 initializeQueue(&queue); 
 enqueue(&queue, 7); 
 enqueue(&queue, 1); 
 enqueue(&queue, 3); 
 enqueue(&queue, 11); 
 enqueue(&queue, 2); 
 printf("Original Queue:\n"); 
 display(&queue); 
 reverseQueue(&queue); 
 printf("Reversed Queue:\n"); 
 display(&queue); 
 return 0; 
}