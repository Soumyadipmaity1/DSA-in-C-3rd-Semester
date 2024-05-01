//A3Q3  WAP to perform addition of two given sparse matrix in 3–tuple/triplet format.

#include <stdio.h>
#include <stdbool.h>
void add_sparse_matrices(int triplets1[][3], int m1, int n1, int triplets2[][3], int m2, int n2, int triplets3[][3]) {
  int i, j;
  for (i = 0; i < m1; i++) {
    for (j = 0; j < n1; j++) {
      triplets3[i][0] = triplets1[i][0];
      triplets3[i][1] = triplets1[i][1];
      triplets3[i][2] = triplets1[i][2];
    }
  }

  for (i = 0; i < m2; i++) {
    for (j = 0; j < n2; j++) {
      if (triplets2[i][0] == i && triplets2[i][1] == j && triplets2[i][2] != 0) {
        bool found = false;
        for (int k = 0; k < m1; k++) {
          if (triplets3[k][0] == i && triplets3[k][1] == j) {
            triplets3[k][2] += triplets2[i][2];
            found = true;
            break;
          }
        }
        if (!found) {
          triplets3[i][0] = i;
          triplets3[i][1] = j;
          triplets3[i][2] = triplets2[i][2];
        }
      }
    }
  }
}

int main() {
  int m1 = 3, n1 = 2;
  int triplets1[][3] = {
    {0, 0, true},
    {1, 1, false},
    {2, 0, false}
  };

  int m2 = 2, n2 = 2;
  int triplets2[][3] = {
    {0, 1, true},
    {1, 0, false}
  };
  int m3 = m1, n3 = n2;
  int triplets3[3][3];
  add_sparse_matrices(triplets1, m1, n1, triplets2, m2, n2, triplets3);
int i,j;
  for (i = 0; i < m3; i++) {
    for (j = 0; j < n3; j++) {
      printf("%d, %d, %d\n", triplets3[i][0], triplets3[i][1], triplets3[i][2]);
    }
  }

  return 0;
}