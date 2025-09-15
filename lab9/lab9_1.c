#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 99999

int n; // number of vertices

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d", j+1);
        return;
    }
    printPath(parent, parent[j]);
    printf("->%d", j+1);
}

void dijkstra(int graph[MAX][MAX], int src) {
    int dist[MAX];     // Shortest distance
    int sptSet[MAX];   // 1 if included in shortest path tree
    int parent[MAX];   // To store shortest path tree

    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        int min = INF, u = -1;

        // Pick the min distance vertex not yet processed
        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }

        sptSet[u] = 1;

        // Update dist[v]
        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF 
                && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Source\tDestination\tCost\tPath\n");
    for (int i = 0; i < n; i++) {
        if (i != src) {
            printf("%d\t%d\t\t%d\t%d->", src+1, i+1, dist[i], src+1);
            printPath(parent, i);
            printf("\n");
        }
    }
}

int main() {
    int src;
    FILE *fp;

    fp = fopen("inDiAdjMat1.dat", "r");
    if (fp == NULL) {
        printf("Error: File not found!\n");
        return 1;
    }

    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];

    // Read adjacency matrix from file
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fp, "%d", &graph[i][j]);
        }
    }

    fclose(fp);

    printf("Enter the Source Vertex: ");
    scanf("%d", &src);

    dijkstra(graph, src-1);

    return 0;
}

