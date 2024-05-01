// 3. WAP to count the number of occurrences of an element in a linked list of n nodes.

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
int countOccurrences(struct Node* head, int target) {
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == target) {
            count++;
        }
        current = current->next;
    }

    return count;
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
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 5);

    printf("Original Linked List: ");
    display(head);

    int target = 2;
    int occurrences = countOccurrences(head, target);

    printf("Number of occurrences of %d in the Linked List: %d\n", target, occurrences);

    return 0;
}
