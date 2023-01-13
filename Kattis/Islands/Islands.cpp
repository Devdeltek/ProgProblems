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

