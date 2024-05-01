//Q1.WAP to represent a given sparse matrix in 3-tuple/triplet format using 2-D array.

#include<stdio.h>
int main()
{
    int a[4][4]={{1, 1, 0, 0},
                  {0 ,0, 2, 0},
                  {0, 0, 0, 1},
                  {9, 8, 0, 0}};
                  printf("The given matrix is :-\n");
                  
    int i,j;
    int nonzero=0;
    int sparse[3][3];


    for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }


    for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
           if(a[i][j]!=0)
           {
            nonzero++;
           }
        }
    }
    sparse[0][2]=nonzero;
    sparse[0][1]=i;
    sparse[0][0]=j;
int s=1;
     for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
           if(a[i][j]!=0)
           {
            sparse[s][0]=i;
            sparse[s][1]=j;
            sparse[s][2]=a[i][j];
            s++;
           }
        }
    }
    printf("\n");
    printf("The sparse matrix is :- \n\n");
    printf ("Row  Column  Nonzero-Element\n");
     for(i=0;i<=6;i++)
    {
        for(j=0;j<=2;j++)
        {
      printf("%d       ",sparse[i][j]);
        }
        printf("\n");
    }
    return 0;
}