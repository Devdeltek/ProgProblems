#include <iostream>
#include <vector>
using namespace std;

void DFS(int i, int j);

int r, c;
int gold = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<string> grid;
vector<vector<int>> visited; 


int main(){
    string temp;
    
    cin >> c >> r;
    vector<int> setup(c);
    
    for(int i = 0; i < r; i++){
        visited.push_back(setup);
    }

    for(int i = 0; i < r; i++){
        cin >> temp;
        grid.push_back(temp);
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(grid[i][j] == 'P' && visited[i][j] == 0){
                DFS(i,j);
            }
        }
    }
    cout << gold;

    return 0;
}

void DFS(int i, int j){
    if(visited[i][j] == 1){
        return;
    }
    if(grid[i][j] == 'G'){
        gold++;
    }

    visited[i][j] = 1;
    for(int k = 0; k < 4; k++){
        int idx = i + dx[k];
        int jdy = j + dy[k];
        if(grid[idx][jdy] == 'T'){
            return;
        }
    }
    for(int k = 0; k < 4; k++){
        int idx = i + dx[k];
        int jdy = j + dy[k];
        if(idx < 0 || idx >= r || jdy < 0 || jdy >= c){
            continue;
        }
        else if(grid[idx][jdy] == '.' || grid[idx][jdy] == 'G'){
            DFS(idx, jdy);
        }
        
    }
}

