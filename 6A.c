#include<stdio.h>
#define infinity 999
void dijkstra(int a[10][10],int n, int s);
int main()
{
int a[10][10], i,j,n,u;
printf("how many vertices\n");
scanf("%d",&n);
printf("\nAdjacency Matrix\n");
for(i=0; i<n; i++)
{
for(j=0; j<n; j++)
{
scanf("%d",&a[i][j]);
}
}
printf("enter starting vaetex\n");
scanf("%d",&u);
dijkstra(a,n,u);
}
void dijkstra(int a[10][10], int n, int s)
{
int cost[10][10],dist[10], pred[10];
int visited[10],next,i,j,mindist,count;
for(i=0; i<n; i++)
{
for(j=0; j<n; j++)
{
if(a[i][j]==0)
cost[i][j]=infinity;
else cost[i][j]=a[i][j];
}
}
for(i=0; i<n; i++)
{
dist[i]=cost[s][i];
pred[i]=s;
visited[i]=0;
}
dist[s]=0;
visited[s]=1;
count=1;
while(count<n-1)
{
mindist=infinity;
for(i=0; i<n; i++)
{
if(dist[i]<mindist&&!visited[i])
{
mindist=dist[i];
next=i;
}
}
visited[next]=1;
for(i=0; i<n; i++)
if(!visited[i])
if(mindist+cost[next][i]<dist[i])
{
dist[i]=mindist+cost[next][i];
pred[i]=next;
}
count++;
}
for(i=0; i<n; i++)
if(i!=s)
{
printf("\n distance of node %d=%d\n",i,dist[i]);
printf("path =%d",i);
j=1;
}
do{
j=pred[j];
printf("%d",j);
}while(j!=s);
}
