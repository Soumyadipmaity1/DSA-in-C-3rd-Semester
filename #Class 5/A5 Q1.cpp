//Q1: WAP to create a double linked list of n nodes anddisplaythe linked list by using suitable user defined functionsforcreate and display operations. 


#include <stdio.h> 
#include <stdlib.h> 
// Define a structure for a double linked list node 
struct Node { 
int data; 
struct Node* prev; 
struct Node* next; 
}; 
// Function to create a new node 
struct Node* createNode(int data) { 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); if (newNode == NULL) { 
printf("Memory allocation failed.\n"); 
exit(1); 
} 
newNode->data = data; 
newNode->prev = NULL; 
newNode->next = NULL; 
return newNode; 
} 
// Function to insert a new node at the end of the list 
void insertAtEnd(struct Node** head, int data) { struct Node* newNode = createNode(data); 
if (*head == NULL) { 
*head = newNode; 
} else { 
struct Node* current = *head; 
while (current->next != NULL) { 
current = current->next; 
} 
current->next = newNode; 
newNode->prev = current; 
} 
}
// Function to display the double linked list 
void display(struct Node* head) { 
printf("Double Linked List: "); 
while (head != NULL) { 
printf("%d -> ", head->data); 
head = head->next; 
} 
printf("NULL\n"); 
} 
int main() { 
struct Node* head = NULL; 
int n, data; 
printf("Enter the number of nodes: "); 
scanf("%d", &n); 
for (int i = 0; i < n; i++) { 
printf("Enter data for node %d: ", i + 1); 
scanf("%d", &data); 
insertAtEnd(&head, data); 
} 
display(head); 
return 0; 
} 
