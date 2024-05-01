//Write a program to read two numbers and compare the numbers using function call by address.

#include <stdio.h>
int compare(int *a, int *b) {
    if (*a > *b) {
        printf("%d is greater than %d\n", *a, *b);
    } else if (*a < *b) {
        printf("%d is less than %d\n", *a, *b);
    } else {
        printf("%d is equal to %d\n", *a, *b);
    }
    return *a,*b;
}
int main() {
    int a, b;
    printf("Enter the first & second number: ");
    scanf("%d %d", &a, &b);
    compare(&a, &b);
    return 0;
}