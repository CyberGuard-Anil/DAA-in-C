#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, start;
    cout << "Enter the Number of Vertices: ";
    cin >> n;
    cout << "Enter the Starting Vertex: ";
    cin >> start;


    vector<vector<int>> cost(n, vector<int>(n));
    cout << "Enter the cost adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 0) cost[i][j] = INT_MAX; 
        }
    }

    vector<int> key(n, INT_MAX);    
    vector<int> parent(n, -1);     
    vector<bool> mstSet(n, false);  

    key[start - 1] = 0; 
    int totalWeight = 0;

    for (int count = 0; count < n - 1; count++) {
       int u = -1, minVal = INT_MAX;
        for (int v = 0; v < n; v++) {
            if (!mstSet[v] && key[v] < minVal) {
                minVal = key[v];
                u = v;
            }
        }

        mstSet[u] = true;
        totalWeight += (parent[u] == -1 ? 0 : cost[u][parent[u]]);

       
        for (int v = 0; v < n; v++) {
            if (cost[u][v] < key[v] && !mstSet[v]) {
                key[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }


    vector<vector<int>> mst(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            mst[i][parent[i]] = mst[parent[i]][i] = cost[i][parent[i]];
        }
    }

    cout << "\nMinimum Spanning Tree (Adjacency Matrix):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (mst[i][j] == INT_MAX ? 0 : mst[i][j]) << " ";
        }
        cout << endl;
    }

    cout << "\nTotal Weight of the Spanning Tree: " << totalWeight << endl;

    return 0;
}

