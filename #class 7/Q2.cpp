//2. Write a menu driven program to implement queue operations such 
//as Enqueue, Dequeue, Peek, Display of elements, IsEmpty using linked 
//list.

 
#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
 int data; 
 struct Node* next; 
}; 
struct Queue { 
 struct Node* front; 
 struct Node* rear; 
}; 
struct Queue* createQueue() { 
 struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue)); 
 queue->front = NULL; 
 queue->rear = NULL; 
 return queue; 
} 
int isEmpty(struct Queue* queue) { 
 return (queue->front == NULL); 
} 
void enqueue(struct Queue* queue, int data) { 
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
 newNode->data = data; 
 newNode->next = NULL; 
 if (isEmpty(queue)) { 
 queue->front = newNode; 
 queue->rear = newNode; 
 } else { 
 queue->rear->next = newNode; 
 queue->rear = newNode; 
 } 
 printf("%d enqueued successfully.\n", data); 
} 
void dequeue(struct Queue* queue) { 
 if (isEmpty(queue)) { 
 printf("Queue is empty. Cannot dequeue.\n"); 
 return; 
 } 
 struct Node* temp = queue->front; 
 int data = temp->data; 
 queue->front = queue->front->next; 
 free(temp); 
 printf("%d dequeued successfully.\n", data); 
 if (queue->front == NULL) { 
 queue->rear = NULL; 
 } 
} 
int peek(struct Queue* queue) { 
 if (isEmpty(queue)) { 
 printf("Queue is empty. Cannot peek.\n"); 
 return -1; 
 } 
 return queue->front->data; 
} 
void display(struct Queue* queue) { 
 if (isEmpty(queue)) { 
 printf("Queue is empty.\n"); 
 return; 
 } 
 printf("Queue elements: "); 
 struct Node* current = queue->front; 
 while (current != NULL) { 
 printf("%d ", current->data); 
 current = current->next; 
 } 
 printf("\n"); 
} 
int main() { 
 struct Queue* queue = createQueue(); 
 int choice, data; 
 while (1) { 
 printf("\nQueue Operations:\n"); 
 printf("1. Enqueue\n"); 
 printf("2. Dequeue\n"); 
 printf("3. Peek\n"); 
 printf("4. Display\n"); 
 printf("5. IsEmpty\n"); 
 printf("6. Exit\n"); 
 printf("Enter your choice: "); 
 scanf("%d", &choice); 
 switch (choice) { 
 case 1: 
 printf("Enter data to enqueue: "); 
 scanf("%d", &data); 
 enqueue(queue, data); 
 break; 
 case 2: 
 dequeue(queue); 
 break; 
 case 3: 
 data = peek(queue); 
 if (data != -1) { 
 printf("Front element: %d\n", data); 
 } 
 break; 
 case 4: 
 display(queue); 
 break; 
 case 5: 
 if (isEmpty(queue)) { 
 printf("Queue is empty.\n"); 
 } else { 
 printf("Queue is not empty.\n"); 
 } 
 break; 
 case 6: 
 printf("Exiting the program.\n"); 
 exit(0); 
 default: 
 printf("Invalid choice. Please try again.\n"); 
 } 
 } 
 return 0; 
}