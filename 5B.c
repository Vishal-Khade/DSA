#include <stdio.h>
#define infinity 999
int a[10][10] , spanning[10][10],n , parent[10],cist[10][10];
int kruskal();
void main()
{
int total_cost = 0;
printf("How many vertices?\n");
scanf("%d", &n);
    
printf("Enter adjacency matrix:\n");
for (int i = 0; i < n; i++) 
{
 for (int j = 0; j < n; j++)
  {
 scanf("%d", &a[i][j]);
}
}
printf("\nThe adjacency matrix:\n");
for (int i = 0; i < n; i++)
 {
for (int j = 0; j < n; j++) 
{
printf("%d\t", a[i][j]);
}
printf("\n");
}
total_cost = kruskal();
printf("\nThe spanning matrix is:\n");
for (int i = 0; i < n; i++) 
{
for (int j = 0; j < n; j++) 
{
printf("%d\t", spanning[i][j]);
}
 printf("\n");
}
printf("The minimum cost of spanning tree is %d\n", total_cost);
}

int kruskal()
{
 int min,mincost,i,j,u,v,k,cost[10][10];
 heapify(a,0,n);
 min=999;
 for(i=0;i<n;i++)
   parent[i]=-1;
   i=0;
   mincost=0;
   while((i<n-1) && (!heapify(a,0,n)))
   {
     for(i=0;i<n;i++)
       for(j=0;j<n;j++)
       if(cost[i][j]<min)
       min=cost[i][j];
   u=a[i];
   v=a[j];
   j=find(u);
   k=find(v);
   if(j!=k)
   {
    i=i+1;
    mincost=mincost+cost[i][j];
    un (j,k);
   }
   heapify(a,i,n);
   }
   if(i!=n-1)
   {
     printf("\n number of spanning tree ");
     }
     else
     
     return (mincost);
   
   }
   
int find(int i)
   {
     while(parent[i])
     i=parent[i];
     return i;   
   }

int un(int i,int j)
{
  
  if(i!=j)
  {
    parent[j]=i;
    return 1;
  }
  return 0;
}
