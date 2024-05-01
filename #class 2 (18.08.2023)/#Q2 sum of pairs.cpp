// Q2 Given an array of integers, and a number ‘sum’. WAP to find the number of pairs of integers in the array whose sum is equal to ‘sum’.

#include <stdio.h>

int main() {
    int arr[] = {1, 4, 8, -2,-4,10,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 6;

    int count = 0;

    for (int i = 0; i < n - 1; i++) 
	{
        for (int j = i + 1; j < n; j++) 
		{
            if (arr[i] + arr[j] == sum) 
			{
                count++;
                printf("(%d, %d)\n", arr[i], arr[j]);
            }
        }
    }

    printf("Number of pairs with sum %d: %d\n", sum, count);

    return 0;
}
