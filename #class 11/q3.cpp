//3. Given an array “container[]” and integer “hunt”. WAP to find 
//whether “hunt” is present in container[] or not. If present, then triple the 
//value of “hunt” and search again. Repeat these steps until “hunt” is not 
//found. Finally return the value of “hunt”. 
//Input : container[] = {1, 2, 3} and hunt = 1 then Output : 9 
//Explanation: Start with hunt = 1. Since it is present in array, it becomes 
//3. Now 3 is present in array and hence hunt becomes 9 . Since 9 is not 
//present, program returns 9. 
 
#include<stdio.h> 
int bsrch(int[],int,int,int,int); 
void sort(int*,int); 
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
int bsrch(int a[],int lb,int ub,int key,int size) 
{ 
if(lb<=ub) 
{ 
int m=(lb+ub)/2; 
if(a[m]==key) 
{ 
return bsrch(a,0,size-1,3*key,size); 
} 
if(key<a[m]) 
return bsrch(a,lb,m-1,key,size); 
else 
return bsrch(a,m+1,ub,key,size); 
} 
else 
{ 
return key;} 
} 
int main() 
{ 
int i,container[20],hunt,n; 
printf("enter size of container\n"); 
scanf("%d",&n); 
printf("Enter elements in the container\n"); 
for(i=0;i<n;i++) 
scanf("%d",&container[i]); 
printf("enter element to be hunted\n"); 
scanf("%d",&hunt); 
int* p=container; 
sort(p,n); 
printf("%d", bsrch(container,0,n,hunt,n)); 
return 0; 
}