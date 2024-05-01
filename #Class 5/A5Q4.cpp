/*Q4: WAP to create a circular double linked list of n nodes and display
the linked list by using suitable user defined functions for create and
display operations. */

#include <stdio.h>
#include <stdlib.h>
// Define a structure for a circular double-linked list node
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
// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head, int data) {
struct Node* newNode = createNode(data);
if (*head == NULL) {
*head = newNode; 
(*head)->next = newNode;
(*head)->prev = newNode;
} else {
struct Node* tail = (*head)->prev;
tail->next = newNode;
newNode->prev = tail;
newNode->next = *head;
(*head)->prev = newNode;
}
}
// Function to display the circular double-linked list
void display(struct Node* head) {
struct Node* current = head;
printf("Circular Double Linked List: ");
if (head != NULL) {
do {
printf("%d -> ", current->data);
current = current->next;
} while (current != head);
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