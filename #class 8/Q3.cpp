
/*3. Write a menu driven program to implement circular queue operations such as 
Enqueue, Dequeue, Peek, Display of elements, IsEmpty using linked list. */


#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
int data; 
struct Node* next; 
}; 
struct CQueue { 
struct Node* rear; 
}; 
void* createNode(int data) { 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
if (newNode != NULL) { 
newNode->data = data; 
newNode->next = NULL; 
} 
return newNode; 
} 
void* createCQueue() {struct CQueue* cqueue = (struct CQueue*)malloc(sizeof(struct 
CQueue)); 
if (cqueue != NULL) { 
cqueue->rear = NULL; 
} 
return cqueue; 
} 
bool isEmpty(struct CQueue* cqueue) { 
return cqueue->rear == NULL; 
} 
void enqueue(struct CQueue* cqueue, int data) { 
struct Node* newNode = (struct Node*)createNode(data); 
if (isEmpty(cqueue)) { 
newNode->next = newNode; 
cqueue->rear = newNode; 
} else { 
newNode->next = cqueue->rear->next; 
cqueue->rear->next = newNode; 
cqueue->rear = newNode; 
} 
printf("Enqueued element: %d\n", data); 
} 
void dequeue(struct CQueue* cqueue) { 
if (isEmpty(cqueue)) { 
printf("Queue underflow\n"); 
} else {struct Node* front = cqueue->rear->next; 
if (front == cqueue->rear) { 
free(front); 
cqueue->rear = NULL; 
} else { 
cqueue->rear->next = front->next; 
free(front); 
} 
printf("Dequeued element\n"); 
} 
} 
void peek(struct CQueue* cqueue) { 
if (isEmpty(cqueue)) { 
printf("Queue is empty\n"); 
} 
else { 
printf("Front element: %d\n", cqueue->rear->next->data); 
} 
} 
void display(struct CQueue* cqueue) { 
if (isEmpty(cqueue)) { 
printf("Queue is empty\n"); 
} else { 
struct Node* temp = cqueue->rear->next;printf("Queue elements: "); 
do { 
printf("%d ", temp->data); 
temp = temp->next; 
} while (temp != cqueue->rear->next); 
printf("\n"); 
} 
} 
void freeCQueue(struct CQueue* cqueue) { 
if (isEmpty(cqueue)) { 
free(cqueue); 
return; 
} 
struct Node* temp = cqueue->rear->next; 
struct Node* nextNode; 
do { 
nextNode = temp->next; 
free(temp); 
temp = nextNode; 
} while (temp != cqueue->rear->next); 
free(cqueue); 
} 
int main() { 
struct CQueue* cqueue = (struct CQueue*)createCQueue(); 
int choice, data; 
while (true) { 
printf("\nMenu:\n"); 
printf("1. Enqueue\n"); 
printf("2. Dequeue\n"); 
printf("3. Peek\n"); 
printf("4. Display\n"); 
printf("5. Exit\n"); 
printf("Enter your choice: "); 
scanf("%d", &choice); 
switch (choice) { 
case 1: 
printf("Enter element to enqueue: "); 
scanf("%d", &data); 
enqueue(cqueue, data); 
break; 
case 2: 
dequeue(cqueue);break; 
case 3: 
peek(cqueue); 
break; 
case 4: 
display(cqueue); 
break; 
case 5:freeCQueue(cqueue); 
printf("Exiting program...\n"); 
exit(0); 
default: 
printf("Invalid choice. Please try again.\n"); 
} 
} 
return 0; 
}