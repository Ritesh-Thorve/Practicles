// 8] Implement DFS to find paths in a city’s metro rail system represented as a graph using an adjacency list.

#include <iostream>
#include <vector>
using namespace std;

// Depth First Search function
void dfs(int station, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[station] = true;
    cout << "Visited station: " << station << endl;

    for (int neighbor : adj[station]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int numStations = 6;   // Number of metro stations

    // Adjacency list representation of metro network
    vector<vector<int>> metroAdj(numStations);

    // Undirected connections between stations
    metroAdj[0] = {1, 2};
    metroAdj[1] = {0, 3};
    metroAdj[2] = {0, 4};
    metroAdj[3] = {1, 5};
    metroAdj[4] = {2};
    metroAdj[5] = {3};

    vector<bool> visited(numStations, false);

    cout << "Starting DFS from Station 0:\n";
    dfs(0, metroAdj, visited);

    return 0;
}


/*
📘 Theory Covered by the Program
1. Graph Representation

The metro rail system is represented as a graph.

Stations → vertices (nodes)

Rail connections → edges

Uses an adjacency list to store connections efficiently.

2. Adjacency List

A graph representation where each vertex stores a list of its neighboring vertices.

Efficient for sparse graphs like metro systems.

Implemented using vector<vector<int>>.

3. Depth First Search (DFS)

DFS is a graph traversal algorithm.

Explores as far as possible along one path before backtracking.

Implemented using recursion.

4. Recursive Traversal

DFS calls itself for unvisited neighboring stations.

Uses the call stack implicitly.

Suitable for exploring paths in a network.

5. Visited Array

A boolean array tracks visited stations.

Prevents infinite loops in cyclic graphs.

Ensures each station is visited only once.

6. Undirected Graph

Metro connections are bidirectional.

Each connection is stored in both stations’ adjacency lists.

7. Real-World Application

DFS can be used to:

Explore reachable stations

Find paths in metro networks

Analyze connectivity in transportation systems

8. Algorithm Complexity

Time Complexity: O(V + E)

Space Complexity: O(V)

where:

V = number of stations

E = number of connections
*/
