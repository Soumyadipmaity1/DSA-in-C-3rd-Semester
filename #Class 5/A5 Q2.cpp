//Q2: WAP to reverse the sequence of elements in a double linked list. 


#include <stdio.h> 
#include <stdlib.h> 
// Define a structure for a double-linked list node 
struct Node { 
int data; 
struct Node* prev; 
struct Node* next; 
}; 
// Function to create a new node 
struct Node* createNode(int data) { 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

if (newNode == NULL) { 
printf("Memory allocation failed.\n"); 
exit(1); 
} 
newNode->data = data; 
newNode->prev = NULL; 
newNode->next = NULL; 
return newNode; 
} 
// Function to reverse the sequence of elements in the double-linkedlist 
void reverse(struct Node** head) { 
struct Node* current = *head; 
struct Node* temp = NULL; 
while (current != NULL) { 
temp = current->prev; 
current->prev = current->next; 
current->next = temp; 
current = current->prev; 
} 
if (temp != NULL) { 
*head = temp->prev; // Update the new head 
} 
} 
// Function to display the double-linked list 
void display(struct Node* head) 
{ 
while (head != NULL) 
{ 
printf("%d -> ", head->data); 
head = head->next; 
} 
printf("NULL\n"); 
}
int main() { 
// Create predefined nodes 
struct Node* head = createNode(1); 
struct Node* second = createNode(2); 
struct Node* third = createNode(3);

// Connect the nodes to form a double-linked list 
head->next = second; 
second->prev = head; 
second->next = third; 
third->prev = second; 
// Display the original double-linked list 
printf("Original double linked list is:-\n"); 
display(head); 
// Reverse the sequence of elements in the double-linked list 
reverse(&head); 
// Display the reversed double-linked list 
printf("Reversed double linked list is:-\n"); 
display(head); 
return 0; 
} 
