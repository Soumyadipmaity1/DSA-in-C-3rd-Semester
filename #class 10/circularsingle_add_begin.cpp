#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

// Utility function to print the list
void printList(struct Node* head) {
  struct Node* temp = head;
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }
  do {
    printf("%d -> ", temp->data);
    temp = temp->next;
  } while (temp != head);
  printf("NULL\n");
}

// Function to delete at the beginning of a circular singly linked list
struct Node* deleteAtBeginning(struct Node* head) {
  if (head == NULL) {
    printf("List is empty\n");
    return NULL;
  }
  // If only one node is present
  if (head->next == head) {
    free(head);
    return NULL;
  }
  // Find the last node
  struct Node* last = head;
  while (last->next != head) {
    last = last->next;
  }
  // Update head and last node pointers
  last->next = head->next;
  head = head->next;
  free(head);
  return head;
}

int main() {
  struct Node* head = NULL;

  // Create a circular linked list
  head = (struct Node*)malloc(sizeof(struct Node));
  head->data = 10;
  head->next = (struct Node*)malloc(sizeof(struct Node));
  head->next->data = 20;
  head->next->next = (struct Node*)malloc(sizeof(struct Node));
  head->next->next->data = 30;
  head->next->next->next = head;

  printf("Original list: \n");
  printList(head);

  // Delete at the beginning
  head = deleteAtBeginning(head);

  printf("List after deletion: \n");
  printList(head);

  return 0;
}
