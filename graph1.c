#include<stdio.h>

void main()
{
    int a[10][10],i,j,n;

    printf("Enter the no of vertices\n");
    scanf("%d",&n);

    printf("Enter the adjacency matrix\n");
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("Enter the values b/w %d and %d\n",i,j);
            scanf("%d",&a[i][j]);

            if (i != j)
            {
                if (a[i][j]!=0 && a[i][j]!=1)
                {
                    a[i][j]=1;
                }
                
            }
            else
            {
                a[i][j]= 0;
            }
             
        }   
    } 
    printf("The adjacency matrix is\n");
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
} 
