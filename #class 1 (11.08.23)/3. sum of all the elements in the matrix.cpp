// displauy sum of all the values in a matrix

#include <stdio.h>

int main() {
  int m, n, i, j, sum;

  printf("Enter the number of rows: ");
  scanf("%d", &m);

  printf("Enter the number of columns: ");
  scanf("%d", &n);
  int matrix[m][n];
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      matrix[i][j] = 0;
    }
  }
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("Enter the element at [%d][%d]: ", i, j);
      scanf("%d", &matrix[i][j]);
    }
  }
  sum = 0;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      sum += matrix[i][j];
    }
  }
  printf("The sum of all the elements in the matrix is: %d\n", sum);
}
