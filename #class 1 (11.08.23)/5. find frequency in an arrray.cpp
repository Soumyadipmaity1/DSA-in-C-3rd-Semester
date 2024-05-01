//Q5 WAP to count the frequency of elements in an array 

#include <stdio.h>

void count_frequency(int arr[], int n) 
{
  int i, j;
  for (i = 0; i < n; i++) 
  {
    int count = 0;
    for (j = 0; j < n; j++) 
	{
      if (arr[i] == arr[j]) 
	  {
        count++;
      }
    }
    printf("%d occurs %d times\n", arr[i], count);
  }
}

int main() 
{
  int arr[] = {1, 2, 3, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  count_frequency(arr, n);

  return 0;
}
