#include <iostream>
#include <vector>
using namespace std;

bool DFS(int i, int j, int moves);

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

    int moves = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(grid[i][j] == 'J'){
                DFS(i,j, moves);
            }
        }
    }
    cout << moves;

    for(int i = 0; i < r; i++){
        cout << grid[i] << endl;
    }

    return 0;
}

bool DFS(int i, int j, int moves){
    if(visited[i][j] == 1){
        return false;
    }

    moves++;

    visited[i][j] = 1;
    for(int k = 0; k < 4; k++){
        int idx = i + dx[k];
        int jdy = j + dy[k];
        if(idx < 0 || idx >= r || jdy < 0 || jdy >= c){
            if(grid[i][j] == '.' || ((grid[i][j] > 48 && grid[i][j] < 57) && grid[i][j] > moves + 48)){
                grid[i][j] = moves + 48;
                return true;
            }
        }
        else if(grid[idx][jdy] == '.')
            if(DFS(idx, jdy, moves) && grid[i][j] == '.'){
                grid[i][j] = moves + 48;
                return true;
            }

    }
    return false;
}

