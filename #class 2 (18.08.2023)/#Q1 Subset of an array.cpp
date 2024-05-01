// Q1. WAP to find whether an array is subset of another array.

#include <stdio.h>
int main() 
{
	
	
    int a[] = {1, 2, 3, 4, 5, 6};
    int m = sizeof(a) / sizeof(a[0]);

    int b[] = {4, 50, 3};
    int n = sizeof(b) / sizeof(b[0]);

    int subset = 1;

    for (int i = 0; i < n; i++) 
	{
		    int y = 0;
        for (int j = 0; j < m; j++) 
		{
            if ( b[i] == a[j]) 
			{
                y = 1;
                break;
            }
        }
        if (!y) 
		{
            subset = 0; 
            break;
        }
    }
    if (subset)
        printf("b is a subset of a");
    else
        printf("b is not a subset of a");
    return 0;
}
