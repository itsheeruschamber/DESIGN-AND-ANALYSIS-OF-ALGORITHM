#include <stdio.h>

int a[10][10], visited[10], n, cost = 0;

void get()
{
    int i, j;
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    printf("\nEnter the cost matrix:\n");
    for (i = 0; i < n; i++)
    {
        printf("\nEnter elements of row %d:\n", i + 1);
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
        visited[i] = 0;
    }
    printf("\n\nThe cost list is:\n\n");
    for (i = 0; i < n; i++)
    {
        printf("\n\n");
        for (j = 0; j < n; j++)
            printf("\t%d", a[i][j]);
    }
}

int least(int c)
{
    int i, nc = -1;
    int min = 999, kmin;
    for (i = 0; i < n; i++)
    {
        if (a[c][i] != 0 && visited[i] == 0)
        {
            if (a[c][i] < min)
            {
                min = a[c][i]; 
                kmin = a[c][i];
                nc = i;
            }
        }
    }
    if (min != 999)
        cost += kmin;
    return nc;
}

void mincost(int city)
{
    int ncity;
    visited[city] = 1;
    printf("%d-->", city + 1);
    ncity = least(city);
    if (ncity == -1)
    {
        ncity = 0;
        printf("%d", ncity + 1);
        cost += a[city][ncity];
        return;
    }
    mincost(ncity);
}

void put()
{
    printf("\n\nMinimum cost: %d", cost);
}

int main()
{
    get();
    printf("\n\nThe path is:\n\n");
    mincost(0);
    put();
    return 0;
}
