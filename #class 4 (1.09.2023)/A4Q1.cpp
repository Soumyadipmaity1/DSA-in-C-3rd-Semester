
/* 1. Write a menu driven program to perform the following operations in a single linked list by using suitable user defined functions for each case.
a) Traversal of the list
b) Check if the list is empty
c) Insert a node at the certain position (at beginning/end/any position)
d) Delete a node at the certain position (at beginning/end/any position)
e) Delete a node for the given key
f) Count the total number of nodes
g) Search for an element in the linked list

Verify & validate each function from main method.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void traverse(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int isEmpty(struct Node* head) {
    return head == NULL;
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    struct Node* current = newNode;


    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    
    return head;
}

struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return head;
    }

    if (position == 1) {
        return insertAtBeginning(head, data);
    }

    struct Node* newNode = createNode(data);
    struct Node* current = head;
    int currentPosition = 1;

    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Invalid position.\n");
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

struct Node* deleteAtPosition(struct Node* head, int position) {
    if (isEmpty(head)) {
        printf("The list is empty. Nothing to delete.\n");
        return head;
    }

    if (position < 1) {
        printf("Invalid position.\n");
        return head;
    }

    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;
    int currentPosition = 1;

    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL || current->next == NULL) {
        printf("Invalid position.\n");
        return head;
    }

    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    traverse(head);
    return head;
}
struct Node* deleteByKey(struct Node* head, int key) {
    if (isEmpty(head)) {
        printf("The list is empty. Nothing to delete.\n");
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
        printf("Key not found in the list.\n");
        return head;
    }

    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
int searchElement(struct Node* head, int key) {
    struct Node* current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;
}

int main() {
struct Node* head;
struct Node* first;
struct Node* second;
struct Node* third;

head=(struct Node*)malloc(sizeof(struct Node));
first=(struct Node*)malloc(sizeof(struct Node));
second=(struct Node*)malloc(sizeof(struct Node));
third=(struct Node*)malloc(sizeof(struct Node));

head->data=10;
head->next=first;


first->data=20;
first->next=second;


second->data=30;
second->next=third;


third->data=30;
third->next=NULL;    
    int choice, data, position, key;
  

    while (1) {
        printf("\nMenu:\n");
        printf("1. Traverse the list\n");
        printf("2. Check if the list is empty\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Insert a node at a specific position\n");
        printf("6. Delete a node at a specific position\n");
        printf("7. Delete a node by key\n");
        printf("8. Count the total number of nodes\n");
        printf("9. Search for an element in the list\n");
        printf("10. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);



        switch (choice) {
            case 1:
                traverse(head);
                break;
            case 2:
                if (isEmpty(head)) {
                    printf("The list is empty.\n");
                } else {
                    printf("The list is not empty.\n");
                }
                break;
            case 3:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 4:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 5:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 7:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                head = deleteByKey(head, key);
                break;
            case 8:
                printf("Total number of nodes: %d\n", countNodes(head));
                break;
            case 9:
                printf("Enter element to search: ");
                scanf("%d", &key);
                position = searchElement(head, key);
                if (position != -1) {
                    printf("Element found at position %d\n", position);
                } else {
                    printf("Element not found in the list.\n");
                }
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

    }

    return 0;
}