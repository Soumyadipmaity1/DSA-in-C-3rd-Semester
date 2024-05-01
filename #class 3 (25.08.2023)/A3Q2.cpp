//Q2 WAP to perform transpose of a given sparse matrix in 3-tuple/triplet format.

#include <stdio.h>

void transpose_sparse_matrix(int triplets[][3], int m, int n, int transposed_triplets[2][3]) {
  int i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (triplets[i][1] == j) {
        transposed_triplets[j][0] = i;
        transposed_triplets[j][1] = triplets[i][0];
        transposed_triplets[j][2] = triplets[i][2];
      }
    }
  }
}

int main() {
  int m = 3, n = 2;
  int triplets[][3] = {
    {0, 0, 1},
    {1, 1, 5},
    {2, 0, 2}
  };

  int transposed_triplets[2][3];
  transpose_sparse_matrix(triplets, m, n, transposed_triplets);
  printf("The transpose of the sparse matrix is: \n");
  for (int i = 0; i < n; i++) {
    printf("(%d, %d, %d)\n", transposed_triplets[i][0], transposed_triplets[i][1], transposed_triplets[i][2]);
  }

  return 0;
}