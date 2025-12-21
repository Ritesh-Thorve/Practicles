#include <iostream>
#include <vector>
using namespace std;
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
int numStations = 6; // Example number of metro stations
vector<vector<int>> metroAdj(numStations);
// Representing metro connections as adjacency list
// Example: Connections (undirected)
metroAdj[0] = {1, 2}; // Station 0 connected to 1 and 2
metroAdj[1] = {0, 3}; // Station 1 connected to 0 and 3
metroAdj[2] = {0, 4}; // Station 2 connected to 0 and 4
metroAdj[3] = {1, 5}; // Station 3 connected to 1 and 5

metroAdj[4] = {2}; // Station 4 connected to 2
metroAdj[5] = {3}; // Station 5 connected to 3
vector<bool> visited(numStations, false);
cout << "Starting DFS from Station 0:" << endl;
dfs(0, metroAdj, visited);
return 0;
}