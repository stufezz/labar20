#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void dfs(int node, const vector<vector<int>>& adjacencyMatrix, vector<bool>& visited, vector<int>& path, vector<vector<int>>& allPaths) {
    visited[node] = true;
    path.push_back(node);

    bool hasUnvisitedNeighbor = false;
    for (int neighbor = 0; neighbor < adjacencyMatrix[node].size(); ++neighbor) {
        if (adjacencyMatrix[node][neighbor] == 1 && !visited[neighbor]) {
            hasUnvisitedNeighbor = true;
            dfs(neighbor, adjacencyMatrix, visited, path, allPaths);
        }
    }

    if (!hasUnvisitedNeighbor) {
        allPaths.push_back(path);
    }

    path.pop_back();
    visited[node] = false;
}

int main() {
    ifstream inputFile("/Users/gxbyc/source/labar20/graph.txt");
    ofstream outputFile("/Users/gxbyc/source/labar20/result.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error open file." << endl;
        return 1;
    }

    int n; // Количество вершин в графе
    inputFile >> n;

    vector<vector<int>> adjacencyMatrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> adjacencyMatrix[i][j];
        }
    }

    int root;
    inputFile >> root;

    vector<bool> visited(n, false);
    vector<int> path;
    vector<vector<int>> allPaths;

    dfs(root, adjacencyMatrix, visited, path, allPaths);

    outputFile << "Way to the root node " << root << ":\n";
    for (const auto& singlePath : allPaths) {
        for (int node : singlePath) {
            outputFile << node << " ";
        }
        outputFile << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
///Cmake и Github
