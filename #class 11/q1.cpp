//1. WAP to read an array of integers and search for an element using 
//linear search.
 
#include<stdio.h> 
#include<stdlib.h> 
void lsrch(int[],int,int); 
int main() 
{ 
int n,i,a[20],key; 
printf("Enter size of array\n"); 
scanf("%d",&n); 
printf("Enter values in the array\n"); 
for(i=0;i<n;i++) 
{ 
scanf("%d",&a[i]); 
} 
printf("Enter element to be searched\n"); 
scanf("%d",&key); 
lsrch(a,n,key); 
return 0; 
} 
void lsrch(int a[],int n,int k) 
{ 
int i; 
for(i=0;i<n;i++) 
{ 
if(a[i]==k) 
{ 
printf("Element found\n"); 
return; 
} 
} 
printf("element not found\n"); 
}