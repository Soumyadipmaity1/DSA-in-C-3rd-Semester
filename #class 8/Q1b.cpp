/*Write a menu driven program to implement Deques (both Input-restricted and 
Output-restricted) operations such as Enqueue, Dequeue, Peek, Display of 
elements, IsEmpty, IsFull using Output restricted:  */ 

#include <stdio.h> 
#include <stdbool.h> 
int queue[20], i, data, R=-1, F=-1, size; 
void enqueueR(int data, int size){ 
if (R==size-1){ 
printf("\n Queue overflow\n"); 
} 
if (F==-1&&R==-1){R=F=0; 
queue[R]=data; 
} 
else{ 
queue[++R]=data; 
} 
} 
void enqueueF(int data, int size){ 
if (F==0){ 
printf("\n Queue overflow\n"); 
} 
if (F==-1&&R==-1){ 
R=F=0; 
queue[F]=data; 
} 
else{ 
queue[--F]=data; 
} 
} 
void dequeue(){ 
if (F==-1&&R==-1){ 
printf("\n underflow \n"); 
} 
queue[F]=0; 
F=F+1;if(F>R){ 
F=-1; 
R=-1; 
} 
} 
void peek(){ 
printf("\n %d \n", queue[F]); 
}


void isEmpty(){ 
if (F==-1&&R==-1){ 
printf("The queue is empty \n"); 
} 
else{ 
printf("The queue is not empty \n"); 
} 
} 
void isFull(){ 
if (R==size-1){ 
printf("\n The queue is full \n"); 
} 
else{ 
printf("\n The queue is not full \n"); 
} 
} 
void display(){ 
for (i=0; i<=size-1; i++){ 
printf("\n %d \n", queue[i]); 
} 
} 
int main(){ 
int choice; 
printf("\n Enter the size of the queue: "); 
scanf("%d", &size); 
while(true){ 
printf("\n 1. enqueue\n"); 
printf("7. enqueue from front\n"); 
printf("2. dequeue\n"); 
printf("3. peek\n"); 
printf("4. display\n"); 
printf("5. check if queue is empty\n");printf("6. check if queue is full\n"); 
printf("Enter your choice: "); 
scanf("%d", &choice); 
switch(choice){ 
case 1: 
printf("\n Enter the element: "); 
scanf("%d", &data); 
enqueueR(data, size); 
break; 
case 2:dequeue(); 
break; 
case 3: 
peek(); 
break; 
case 4: 
display(); 
break; 
case 5: 
isEmpty(); 
break; 
case 6: 
isFull(); 
break; 
case 7: 
printf("\n Enter the element: "); 
scanf("%d", &data); 
enqueueF(data, size); 
break; 
default: 
printf("Invalid choice\n"); 
} 
} 
return 0; 
} 