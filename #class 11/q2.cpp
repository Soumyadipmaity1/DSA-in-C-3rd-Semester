//2. WAP to read an array of integers and search for an element using 
//binary search.
 
#include<stdio.h> 
void bsrch(int[],int,int,int); 
void sort(int*,int); 
int main() 
{ 
int i,a[20],key,n; 
printf("enter size of array\n"); 
scanf("%d",&n); 
printf("Enter elements in the array\n"); 
for(i=0;i<n;i++) 
scanf("%d",&a[i]); 
printf("enter element to be searched\n"); 
scanf("%d",&key); 
int* p=a; 
sort(p,n); 
bsrch(a,0,n,key); 
return 0; 
} 
void sort(int *a,int n) 
{ 
int i,j; 
for(i=0;i<n;i++) 
{ 
for(j=0;j<n-1-i;j++) 
{ 
if(*(a+j)>*(a+j+1)) 
{ 
int t=*(a+j); 
*(a+j)=*(a+j+1); 
*(a+j+1)=t; 
} 
} 
} 
} 
void bsrch(int a[],int lb,int ub,int key) 
{if(lb>ub) 
{ 
printf("element not found\n"); 
return; 
} 
else 
{ 
int m=(lb+ub)/2; 
if(a[m]==key) 
{ 
printf("Element found\n"); 
return; 
} 
if(key<a[m]) 
bsrch(a,lb,m-1,key); 
else 
bsrch(a,m+1,ub,key); 
} 
}