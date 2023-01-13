//Class Example
// C++ program to print DFS traversal from
// a given vertex in a given graph
#include <bits/stdc++.h>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

// Driver's code
int main()
{
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";

    // Function call
    g.DFS(2);

    return 0;
}

// improved by Vishnudev C

//Islands example

#include <iostream>
#include <vector>
using namespace std;

void DFS(int i, int j);

int r, c;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<string> grid;
vector<vector<int>> visited; 


int main(){
    string temp;
    
    cin >> r >> c;
    vector<int> setup(c);
    
    for(int i = 0; i < r; i++){
        visited.push_back(setup);
    }

    for(int i = 0; i < r; i++){
        cin >> temp;
        grid.push_back(temp);
    }

    int iCount = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(grid[i][j] == 'L' && visited[i][j] == 0){
                iCount++;
                DFS(i,j);
            }
        }
    }
    cout << iCount;

    return 0;
}

void DFS(int i, int j){
    if(visited[i][j] == 1){
        return;
    }

    visited[i][j] = 1;
    for(int k = 0; k < 4; k++){
        int idx = i + dx[k];
        int jdy = j + dy[k];
        if(idx < 0 || idx >= r || jdy < 0 || jdy >= c){
            continue;
        }
        else if(grid[idx][jdy] == 'L' || grid[idx][jdy] == 'C')
            DFS(idx, jdy);
    }
}

