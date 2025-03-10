#include<stdio.h>
int a[20][20], vis[20],stack[20],top=-1;
void bfs(int i,int n);
void push(int item);
int pop();
void main()
{
int i,j,n,s;
printf("\nEnter the adjacency matrix\t");
printf("\nHow many vertices \t");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("\nEnter the value if there is edge between %d and %d\t",i,j);
scanf("%d",&a[i][j]);
}
}
printf("\nThe Adjacency matrix is \n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("%d\t",a[i][j]);
}
   printf("\n");
    }
   printf("\nEnter the starting vertex\t\n");
   scanf("%d",&s);
   for(i=1;i<=n;i++)
   vis[i]=0;
   bfs(s,n);
   }
   
   void bfs(int s,int n)
   {
   int i,k;
   push(s);
   vis[s]=1;
   k=pop();
   if(k!=0)
   printf("%d",k);
   while(k!=0)
   {
    for(i=1;i<n;i++)
    if((a[k][i]!=0)&&(vis[i]==0))
    {
    push(i);
    vis[i]=1;
   
    }
   k=pop();
   if(k!=0)
     printf("%d",k);
     }
    for(i=1;i<=n;i++)
     if(vis[i]==0)
     bfs(i,n);
     }
    void push(int item)
    {
     if(top==19)
    printf("\nQueue overflow");
    else 
    stack[++top]=item;
    }
    int pop()
    {
    int k;
   if(top==1)
   return(0);
   else
   {
   k=stack[top--];
   return(k);
   }
   }
   
  
   
