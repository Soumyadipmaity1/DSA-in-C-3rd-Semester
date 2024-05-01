// Write a menu driven program to implement queue operations such 
//as Enqueue, Dequeue, Peek (display the front content), Display of 
//elements, IsEmpty, IsFull using array. 

#include <stdio.h> 
#include <stdlib.h> 
#define MAX_SIZE 100 
int queue[MAX_SIZE]; 
int front = -1; 
int rear = -1; 
int isEmpty() { 
 return (front == -1); 
} 
int isFull() { 
 return (rear == MAX_SIZE - 1); 
} 
void enqueue(int data) { 
 if (isFull()) { 
 printf("Queue is full. Cannot enqueue.\n"); 
 return; 
 } 
 if (isEmpty()) { 
 front = 0; 
 } 
 rear++; 
 queue[rear] = data; 
 printf("%d enqueued successfully.\n", data); 
} 
void dequeue() { 
 if (isEmpty()) { 
 printf("Queue is empty. Cannot dequeue.\n"); 
 return; 
 } 
 int data = queue[front]; 
 front++; 
 if (front > rear) { 
 front = rear = -1; 
 } 
 printf("%d dequeued successfully.\n", data); 
} 
int peek() { 
 if (isEmpty()) { 
 printf("Queue is empty. Cannot peek.\n"); 
 return -1; 
 } 
 return queue[front]; 
} 
void display() { 
 if (isEmpty()) { 
 printf("Queue is empty.\n"); 
 return; 
 } 
 printf("Queue elements: "); 
 for (int i = front; i <= rear; i++) { 
 printf("%d ", queue[i]); 
 } 
 printf("\n"); 
} 
int main() { 
 int choice, data; 
 while (1) { 
 printf("\nQueue Operations:\n"); 
 printf("1. Enqueue\n"); 
 printf("2. Dequeue\n"); 
 printf("3. Peek\n"); 
 printf("4. Display\n"); 
 printf("5. IsEmpty\n"); 
 printf("6. IsFull\n"); 
 printf("7. Exit\n"); 
 printf("Enter your choice: "); 
 scanf("%d", &choice); 
 switch (choice) { 
 case 1: 
 printf("Enter data to enqueue: "); 
 scanf("%d", &data); 
 enqueue(data); 
 break; 
 case 2: 
 dequeue(); 
 break; 
 case 3: 
 data = peek(); 
 if (data != -1) { 
 printf("Front element: %d\n", data); 
 } 
 break; 
 case 4: 
 display(); 
 break; 
 case 5: 
 if (isEmpty()) { 
 printf("Queue is empty.\n"); 
 } else { 
 printf("Queue is not empty.\n"); 
 } 
 break; 
 case 6: 
 if (isFull()) { 
 printf("Queue is full.\n"); 
 } else { 
 printf("Queue is not full.\n"); 
 } 
 break; 
 case 7: 
 printf("Exiting the program.\n"); 
 exit(0); 
 default: 
 printf("Invalid choice. Please try again.\n"); 
 } 
 } 
 return 0; 
}