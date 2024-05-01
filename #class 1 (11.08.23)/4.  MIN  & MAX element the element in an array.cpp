// Q4 WAP to display min & max values of an array

#include <stdio.h>
int main() {
  int arr[] = {10, 4, 2, 9, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  int min = arr[0];
  int max = arr[0];

  for (int i = 1; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    } else if (arr[i] > max) {
      max = arr[i];
    }
  }

  printf("The minimum value is %d\n", min);
  printf("The maximum value is %d\n", max);

  return 0;
}
