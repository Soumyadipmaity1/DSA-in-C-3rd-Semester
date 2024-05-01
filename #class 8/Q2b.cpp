/*2. Write a menu driven program to implement Deques (both Input-restricted 
and Output-restricted) operations such as Enqueue, Dequeue, Peek, Display of 
elements, IsEmpty, IsFull using linked list. 
Output restricted: */


#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>

struct node { 
int data; 
struct node* next; 
}; 
struct deque { 
struct node* front; 
struct node* rear; 
int size; 
int count; 
}; 
void* createNode(int data) { 
struct node* newNode = (struct node*)malloc(sizeof(struct node)); 
if (newNode != NULL) { 
newNode->data = data; 
newNode->next = NULL; 
} 
return newNode; 
} 
void* createDeque(int size) { 
struct deque* dq = (struct deque*)malloc(sizeof(struct deque));if (dq != NULL) { 
dq->front = NULL; 
dq->rear = NULL; 
dq->size = size; 
dq->count = 0; 
} 
return dq; 
} 
bool isFull(struct deque* dq) { 
return dq->count == dq->size; 
} 
bool isEmpty(struct deque* dq) { 
return dq->count == 0; 
} 
void enqueueFront(struct deque* dq, int data) { 
if (isFull(dq)) { 
printf("Deque overflow\n"); 
} else { 
struct node* newNode = (struct node*)createNode(data); 
if (newNode != NULL) { 
if (isEmpty(dq)) { 
dq->front = newNode; 
dq->rear = newNode; 
} else { 
newNode->next = dq->front; 
dq->front = newNode; 
} 
dq->count++; 
printf("Enqueued element at the front: %d\n", data); 
} else { 
printf("Memory allocation error\n"); 
} 
} 
} 
void enqueueRear(struct deque* dq, int data) { 
if (isFull(dq)) { 
printf("Deque overflow\n"); 
} else { 
struct node* newNode = (struct node*)createNode(data); 
if (newNode != NULL) { 
if (isEmpty(dq)) { 
dq->front = newNode; 
dq->rear = newNode; 
} else { 
dq->rear->next = newNode;dq->rear = newNode; 
} 
dq->count++; 
printf("Enqueued element at the rear: %d\n", data); 
} else { 
printf("Memory allocation error\n"); 
} 
}} 
void dequeueFront(struct deque* dq) { 
if (isEmpty(dq)) { 
printf("Deque underflow\n"); 
} else { 
struct node* temp = dq->front; 
dq->front = dq->front->next; 
free(temp); 
dq->count--; 
printf("Element dequeued from the front\n"); 
} 
} 
void display(struct deque* dq) { 
if (isEmpty(dq)) { 
printf("Deque is empty\n"); 
} else { 
printf("Deque elements: "); 
struct node* temp = dq->front; 
while (temp != NULL) { 
printf("%d ", temp->data); 
temp = temp->next; 
} 
printf("\n"); 
} 
} 
void freeDeque(struct deque* dq) { 
struct node* temp = dq->front; 
while (temp != NULL) { 
struct node* current = temp; 
temp = temp->next; 
free(current); 
} 
free(dq); 
} 
int main() { 
int size, choice, data; 
printf("Enter the size of the deque: "); 
scanf("%d", &size); 
struct deque* dq = (struct deque*)createDeque(size); 
while (true) { 
printf("\nMenu:\n"); 
printf("1. Enqueue Front\n"); 
printf("2. Enqueue Rear\n"); 
printf("3. Dequeue Front\n"); 
printf("4. Display\n"); 
printf("5. Exit\n"); 
printf("Enter your choice: "); 
scanf("%d", &choice); 
switch (choice) { 
case 1:printf("Enter element to enqueue at the front: "); 
scanf("%d", &data); 
enqueueFront(dq, data); 
break; 
case 2: 
printf("Enter element to enqueue at the rear: "); 
scanf("%d", &data); 
enqueueRear(dq, data);break; 
case 3: 
dequeueFront(dq); 
break; 
case 4: 
display(dq); 
break; 
case 5: 
freeDeque(dq); 
printf("Exiting program...\n"); 
exit(0); 
default: 
printf("Invalid choice. Please try again.\n"); 
} 
} 
return 0; 
} 