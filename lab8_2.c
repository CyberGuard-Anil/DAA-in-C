#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

// Sorting function for edges by weight
int cmp(const void* a, const void* b) {
    struct Edge* e1 = (struct Edge*)a;
    struct Edge* e2 = (struct Edge*)b;
    return e1->w - e2->w;
}

// Find with path compression
int findParent(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = findParent(parent, parent[i]);
    return parent[i];
}

// Union by rank
void unionSet(int parent[], int rank[], int u, int v) {
    int pu = findParent(parent, u);
    int pv = findParent(parent, v);

    if (rank[pu] < rank[pv]) {
        parent[pu] = pv;
    } else if (rank[pv] < rank[pu]) {
        parent[pv] = pu;
    } else {
        parent[pv] = pu;
        rank[pu]++;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Edge edges[m];
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Sort edges by weight
    qsort(edges, m, sizeof(struct Edge), cmp);

    int parent[n + 1], rank[n + 1];
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int totalWeight = 0;
    printf("Edge\tCost\n");

    int edgesInMST = 0;
    for (int i = 0; i < m && edgesInMST < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int pu = findParent(parent, u);
        int pv = findParent(parent, v);

        if (pu != pv) {
            printf("%d-%d\t%d\n", u, v, w);
            totalWeight += w;
            unionSet(parent, rank, pu, pv);
            edgesInMST++;
        }
    }

    printf("Total Weight of the Spanning Tree: %d\n", totalWeight);
    return 0;
}

