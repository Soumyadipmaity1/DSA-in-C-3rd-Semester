/* Q5   Write a program to perform the following operations on a given square matrix using functions: 
i.   Find the no.of nonzero elements
ii.  Display upper triangular matrix
iii. Display the elements of just above and below the main diagonal */

#include <stdio.h>
#define N 3 
void readMatrix(int matrix[N][N]) {
    printf("Enter matrix elements:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}
int countNonZero(int matrix[N][N]) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}
void displayUpperTriangular(int matrix[N][N]) {
    printf("Upper triangular matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i <= j) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
void displayAboveAndBelowDiagonal(int matrix[N][N]) {
    printf("Elements above and below the main diagonal:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j - 1) {
                printf("Above: %d, ", matrix[i][j]);
            }
            if (i == j + 1) {
                printf("Below: %d\n", matrix[i][j]);
            }
        }
    }
}
int main() {
    int matrix[N][N];
    readMatrix(matrix);
    printf("No. of nonzero elements: %d\n", countNonZero(matrix));
    displayUpperTriangular(matrix);
    displayAboveAndBelowDiagonal(matrix);
    return 0;
}

