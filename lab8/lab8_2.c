#include <stdio.h>
#include <stdlib.h>


struct Edge {
    int u, v, w;
};


int parent[100], rank[100];


int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}


void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}


int cmp(const void *a, const void *b) {
    struct Edge *e1 = (struct Edge *)a;
    struct Edge *e2 = (struct Edge *)b;
    return e1->w - e2->w;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Edge edges[m];

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }


    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }


    qsort(edges, m, sizeof(struct Edge), cmp);

    int totalCost = 0;

    printf("Edge \tCost\n");

    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;


        if (find(u) != find(v)) {
            unionSet(u, v);
            printf("%d--%d \t%d\n", u, v, w);
            totalCost += w;
        }
    }

    printf("Total Weight of the Spanning Tree: %d\n", totalCost);

    return 0;
}

