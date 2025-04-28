```c++
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited){
    cout<<node<< " ";
    visited[node] = true;

    for (int neighbor : graph[node]){
        if(!visited[neighbor]){
            dfs(neighbor, graph, visited);

        }
    }
}

void bfs(int start, vector<vector<int>>& graph){
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";

        for (int neighbor : graph[node]){
            if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main(){
    int n = 6;

    vector<vector<int>> graph(n);

    graph[0] = {1, 2};
    graph[1] = {0, 3};
    graph[2] = {0, 3, 4};
    graph[3] = {1, 2};
    graph[4] = {2, 5};
    graph[5] = {4};

    cout<< "DFS starting at 0: "<<endl;
    vector<bool> visited(n, false);
    dfs(0, graph, visited);

    cout<< "BFS starting at 0: "<<endl;
    bfs(0, graph);

    return 0;

}
```
Youtube Video: https://youtu.be/H_keVBCGkk8
