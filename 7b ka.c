#include <stdio.h>
#include <stdlib.h>

int comparator(const void* p1, const void* p2) {
    const int(*x)[3] = (const int(*)[3])p1;
    const int(*y)[3] = (const int(*)[3])p2;
    return (*x)[2] - (*y)[2];
}

void makeset(int parent[], int rank[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int component) {
    if (parent[component] == component)
        return component;
    return parent[component] = findParent(parent, parent[component]);
}

void unionset(int u, int v, int parent[], int rank[], int n) {
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[u] > rank[v]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskalAlgo(int n, int edge[][3]) {
    qsort(edge, n, sizeof(edge[0]), comparator);
    int parent[n];
    int rank[n];
    makeset(parent, rank, n);
    int mincost = 0;
    int i;
    printf("Following are the edges in the constructed matrix:\n");
    for (i = 0; i < n; i++) {
        int v1 = findParent(parent, edge[i][0]);
        int v2 = findParent(parent, edge[i][1]);
        int wt = edge[i][2];
        if (v1 != v2) {
            unionset(v1, v2, parent, rank, n);
            mincost += wt;
            printf("%d--%d==%d\n", edge[i][0], edge[i][1], wt);
        }
    }
    printf("Minimum cost spanning tree: %d\n", mincost);
}

int main() {
    int edge[5][3] = {
        {0, 1, 0},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    kruskalAlgo(5, edge);
    return 0;
}
