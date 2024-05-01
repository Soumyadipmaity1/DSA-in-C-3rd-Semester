/* Q4 4. WAP to create a 1-D array of n elements and perform the following menu based operations using function.
a. insert a given element at specific position.
b. delete an element from a specific position of the array.
c. linear search to search an element
d. traversal of the array */

#include <stdio.h>
#define MAX_SIZE 100
void insertElement(int arr[], int *size, int element, int position) {
    if (*size >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("Invalid position for insertion.\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
}
void deleteElement(int arr[], int *size, int position) {
    if (*size <= 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    if (position < 0 || position >= *size) {
        printf("Invalid position for deletion.\n");
        return;
    }
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1; 
}
void traverseArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, position, searchKey, result;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Linear search\n");
        printf("4. Traverse array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position for insertion: ");
                scanf("%d", &position);
                insertElement(arr, &size, element, position);
                break;
            case 2:
                printf("Enter position for deletion: ");
                scanf("%d", &position);
                deleteElement(arr, &size, position);
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &searchKey);
                result = linearSearch(arr, size, searchKey);
                if (result != -1) {
                    printf("Element found at index %d\n", result);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 4:
                traverseArray(arr, size);
                break;
            case 5:
                printf("Exiting...\n");
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}