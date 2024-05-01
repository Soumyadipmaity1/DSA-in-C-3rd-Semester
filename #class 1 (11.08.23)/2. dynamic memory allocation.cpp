//Q2 WAP to find the input and dispaly the values in an array using dynamic memory allocation

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  int *arr;
  printf("Enter the number of array elements: ");
  scanf("%d", &n);
  arr = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    printf("Enter the %dth element: ", i + 1);
    scanf("%d", arr + i);
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", *(arr + i));
  }
  printf("\n");
  free(arr);

  return 0;
}
