#include <stdio.h>
#define infinity 999

int prims();
int a[10][10], spanning[10][10], n;

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

    total_cost = prims();
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

int prims()
{
    int distance[10], visited[10], from[10], cost[10][10];
    int mincost = 0, noe = n - 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
                cost[i][j] = infinity;
            else
                cost[i][j] = a[i][j];

            spanning[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        distance[i] = cost[0][i];
        from[i] = 0;
        visited[i] = 0;
    }

    visited[0] = 1;

    while (noe > 0)
    {
        int mindist = infinity, v = -1;

        for (int i = 1; i < n; i++)
        {
            if (!visited[i] && distance[i] < mindist)
            {
                mindist = distance[i];
                v = i;
            }
        }

        if (v == -1)
            break;

        int u = from[v];
        spanning[u][v] = distance[v];
        spanning[v][u] = distance[v];

        mincost += distance[v];
        visited[v] = 1;
        noe--;

        for (int i = 1; i < n; i++)
        {
            if (!visited[i] && cost[i][v] < distance[i])
            {
                from[i] = v;
                distance[i] = cost[i][v];
            }
        }
    }

    return (mincost);
}
