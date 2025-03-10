#include <stdio.h>
int a[10][10], indeg[10], flag[10], c = 1;
int i, j, k, n;
void main()
{
    printf("how many vertices\n");
    scanf("%d", &n);
    printf("enter adjacency matrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("the adjajacency matrix is\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < n; i++)
    {
        indeg[i] = 0;
        flag[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            indeg[i] += a[j][i];
        }
    }
    while (c <= n)
    {
        for (k = 0; k < n; k++)
        {
            if ((indeg[k] == 0) && (flag[k] == 0))
            {
                printf("%d", k + 1);
                flag[k] = 1;
            }
        }
        for (i = 0; i < n; i++)
        {
            for (k = 0; k < n; k++)
            {
                if (a[i][k] == 1)
                    indeg[k]--;
            }
        }
        c++;
    }
}
