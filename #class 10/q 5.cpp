#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev,*next;
};

struct Node* removeDuplicatesAndReverse(struct Node* head) {
    struct Node* current = head;
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* nextNode = current->next->next;
            free(current->next);
            current->next = nextNode;
            if (nextNode != NULL) {
                nextNode->prev = current;
            }
        } else {
            current = current->next;
        }
    }
    current = head;
    while (current->next != NULL) {
        struct Node* temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = current->prev;
    }
    head = current;

    return head;
}
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}
int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->prev = head;
    head->next->next = newNode(2);
    head->next->next->prev = head->next;
    head->next->next->next = newNode(3);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = newNode(3);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = newNode(4);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    printf("Original List:\n");
    printList(head);
    head = removeDuplicatesAndReverse(head);
    printf("\nList after removing duplicates and reversing without exchanging content:\n");
    printList(head);
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}