//1. Write a menu-driven program to implement circular queue 
//operations such as Enqueue, Dequeue, Peek, Display of elements, 
//IsEmpty, IsFull using Array. 
#include <stdio.h> 
#include <stdlib.h> 
#define MAX_SIZE 10 
int front = -1, rear = -1; 
int queue[MAX_SIZE]; 
int is_empty() { 
return front == -1; 
} 
int is_full() { 
return (rear + 1) % MAX_SIZE == front; 
} 
void enqueue(int data) { 
if (is_full()) { 
printf("Queue is full. Cannot enqueue.\n"); 
} else { 
if (is_empty()) { 
front = rear = 0; 
} else { 
rear = (rear + 1) % MAX_SIZE; 
} 
queue[rear] = data; 
printf("Enqueued: %d\n", data); 
} 
} 
void dequeue() { 
if (is_empty()) { 
printf("Queue is empty. Cannot dequeue.\n"); 
} else { 
int data = queue[front]; 
if (front == rear) { 
front = rear = -1; 
} else { 
front = (front + 1) % MAX_SIZE; 
} 
printf("Dequeued: %d\n", data); 
} 
} 
void peek() { 
if (is_empty()) { 
printf("Queue is empty. Nothing to peek.\n"); 
} else { 
printf("Peeked element: %d\n", queue[front]); 
} 
}void display() { 
if (is_empty()) { 
printf("Queue is empty. Nothing to display.\n"); 
} else { 
printf("Queue elements: "); 
int i = front; 
do { 
printf("%d ", queue[i]); 
i = (i + 1) % MAX_SIZE; 
} while (i != (rear + 1) % MAX_SIZE); 
printf("\n"); 
} 
} 
int main() { 
int choice, data; 
while (1) { 
printf("\nMenu:\n"); 
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
printf("Enter the element to enqueue: "); 
scanf("%d", &data); 
enqueue(data); 
break; 
case 2: 
dequeue(); 
break; 
case 3: 
peek(); 
break; 
case 4: 
display(); 
break; 
case 5: 
if (is_empty()) { 
printf("Queue is empty.\n"); 
} else { 
printf("Queue is not empty.\n"); 
} 
break; 
case 6: 
if (is_full()) { 
printf("Queue is full.\n"); 
} else { 
printf("Queue is not full.\n");} 
break; 
case 7: 
printf("Exiting the program.\n"); 
exit(0); 
default: 
printf("Invalid choice. Please select a valid option.\n"); 
} 
} 
return 0; 
} 
