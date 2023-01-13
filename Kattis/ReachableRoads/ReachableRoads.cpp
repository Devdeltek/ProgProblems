#include <iostream>
using namespace std;



int main(){
    int graphs, nodes, links, tempStart, tempEnd;
    cin >> n;
    for(int i = 0; i < graphs; i++){
        cin >> nodes >> links;
        vector<int> row(nodes, 0);
        vector<vector<int>> graph(nodes, row);

        for(int j = 0; j < links; j++){
            cin >> tempStart >> tempEnd;

            graph[tempStart][tempEnd] = 1;
            graph[tempEnd][tempStart] = 1;
        }

        int connected_components = 0;

        for(int j = 0; j < nodes; j++){
            if(visited[i]);
        }
    }
}

