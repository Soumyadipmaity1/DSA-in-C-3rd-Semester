
// Q1 swap to numbers using call by reference

 #include <stdio.h>

void swapByReference(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 5, b = 10;
    
    printf("Before swapping: a = %d, b = %d\n", a, b);
    swapByReference(&a, &b);
    printf("After swapping (call by reference): a = %d, b = %d\n", a, b);
    
    return 0;
}



