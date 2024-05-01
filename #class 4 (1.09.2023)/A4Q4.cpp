// 4. WAP to remove duplicates from a linked list of n nodes.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void removeDuplicates(struct Node* head) {
    if (head == NULL) {
        return;
    }
    int hashTable[1000] = {0};
    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL) {
        int data = current->data;

        if (hashTable[data]) {
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            hashTable[data] = 1;
            prev = current;
            current = current->next;
        }
    }
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

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 4);
    insert(&head, 5);

    printf("Original Linked List: ");
    display(head);

    removeDuplicates(head);

    printf("Linked List after removing duplicates: ");
    display(head);

    return 0;
}
