
//Q1 swap two numbers using call by value 

#include <stdio.h>

void swapByValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 5, b = 10;
    
    printf("Before swapping: a = %d, b = %d\n", a, b);
    swapByValue(a, b);
    printf("After swapping (call by value): a = %d, b = %d\n", a, b);
    
    return 0;
}