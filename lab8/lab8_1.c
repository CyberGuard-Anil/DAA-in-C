#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 50

int main() {
    int n, start;
    FILE *fp;


    fp = fopen("inUnAdjMat.dat", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }


    fscanf(fp, "%d", &n);

    int cost[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fp, "%d", &cost[i][j]);
            if (cost[i][j] == 0) cost[i][j] = INT_MAX; 
        }
    }
    fclose(fp);


    printf("Enter the Starting Vertex: ");
    scanf("%d", &start);

    int key[MAX], parent[MAX];
    bool mstSet[MAX];
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[i] = -1;
    }

    key[start - 1] = 0;
    int totalWeight = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INT_MAX, u = -1;

        for (int v = 0; v < n; v++) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        mstSet[u] = true;
        if (parent[u] != -1)
            totalWeight += cost[u][parent[u]];

        for (int v = 0; v < n; v++) {
            if (cost[u][v] < key[v] && !mstSet[v]) {
                key[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }


    int mst[MAX][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mst[i][j] = 0;

    for (int i = 0; i < n; i++) {
        if (parent[i] != -1)
            mst[i][parent[i]] = mst[parent[i]][i] = cost[i][parent[i]];
    }

    printf("\nMinimum Spanning Tree (Adjacency Matrix):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mst[i][j] == INT_MAX) printf("0 ");
            else printf("%d ", mst[i][j]);
        }
        printf("\n");
    }

    printf("\nTotal Weight of the Spanning Tree: %d\n", totalWeight);

    return 0;
}

