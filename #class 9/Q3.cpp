//3. WAP to implement a stack using queue data structure. 


#include <stdio.h> 
#include <stdlib.h> 
#define MAX_SIZE 100 
struct Queue { 
int items[MAX_SIZE]; 
int front, rear; 
}; 
typedef struct Queue Queue; 
void initialize(Queue* queue) { 
queue->front = queue->rear = -1; 
} 
int is_empty(Queue* queue) { 
return queue->front == -1; 
} 
int is_full(Queue* queue) { 
return (queue->rear + 1) % MAX_SIZE == queue->front; 
} 
void enqueue(Queue* queue, int value) { 
if (!is_full(queue)) { 
if (is_empty(queue)) { 
queue->front = queue->rear = 0; 
} else { 
queue->rear = (queue->rear + 1) % MAX_SIZE; 
} 
queue->items[queue->rear] = value; 
} else { 
printf("Queue is full\n"); 
} 
} 
int dequeue(Queue* queue) { 
if (!is_empty(queue)) { 
int data = queue->items[queue->front]; 
if (queue->front == queue->rear) { 
queue->front = queue->rear = -1; 
} else { 
queue->front = (queue->front + 1) % MAX_SIZE;} 
return data; 
} else { 
printf("Queue is empty\n"); 
return -1; 
} 
} 
void push(Queue* q1, Queue* q2, int value) { 
if (is_empty(q1)) { 
enqueue(q1, value) 
; 
} else { 
while (!is_empty(q1)) { 
enqueue(q2, dequeue(q1)); 
} 
enqueue(q1, value); 
while (!is_empty(q2)) { 
enqueue(q1, dequeue(q2)); 
} 
} 
} 
int pop(Queue* q1) { 
if (!is_empty(q1)) { 
return dequeue(q1); 
} else { 
printf("Stack is empty\n"); 
return -1; 
} 
} 
int main() { 
Queue q1, q2; 
initialize(&q1); 
initialize(&q2); 
int choice, data; 
while (1) { 
printf("\nMenu:\n"); 
printf("1. Push\n"); 
printf("2. Pop\n"); 
printf("3. Exit\n"); 
printf("Enter your choice: "); 
scanf("%d", &choice); 
switch (choice) { 
case 1: 
printf("Enter the element to push onto the stack: "); 
scanf("%d", &data); 
push(&q1, &q2, data); 
break; 
case 2: 
data = pop(&q1); 
if (data != -1) { 
printf("Popped: %d\n", data);} 
break; 
case 3: 
printf("Exiting the program.\n"); 
exit(0); 
default: 
printf("Invalid choice. Please select a valid option.\n"); 
} 
} 
return 0; 
}