/* 2. WAP to search an element in a simple linked list, if found delete that node
and insert that node at beginning. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}
struct Node* deleteNode(struct Node* head, int key) {
    if (head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return head;
    }
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;
    while (current->next != NULL && current->next->data != key) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Element not found in the list.\n");
        return head;
    }

    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}
int search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int element;

    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);
    
    printf("Original Linked List: ");
    display(head);
    
    printf("Enter the element to search and move to the beginning: ");
    scanf("%d", &element);

    if (search(head, element)) {
        head = deleteNode(head, element);
        head = insertAtBeginning(head, element);
        printf("Element found and moved to the beginning.\n");
    } else {
        printf("Element not found in the list.\n");
    }

    printf("Modified Linked List: ");
    display(head);

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}