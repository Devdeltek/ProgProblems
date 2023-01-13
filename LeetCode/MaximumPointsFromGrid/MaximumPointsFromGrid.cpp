class Solution {

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int r;
    int c;
    int point = 0;
    vector<vector<int>> visited;

public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<int> points;
        int target;
        r = grid.size();
        c = grid[0].size();

        vector<int> setup(c);
    
        for(int i = 0; i < r; i++){
            visited.push_back(setup);
        }
        for(int i = 0; i < queries.size(); i++){
            target = queries[i];
            point = 0;
            for(int k = 0; k < r; k++){
                for(int l = 0;  l < c; l++){
                    visited[k][l] = 0;
                }
            }
            DFS(grid, 0, 0, target);
            points.push_back(point);
        }
        return points;
    }

    void DFS(vector<vector<int>>& board, int i, int j, int target){
        if(visited[i][j] == 1){
            return;
        }
        if(board[i][j] >= target){
            return;
        }
        point++;
        visited[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int idx = i + dx[k];
            int jdy = j + dy[k];
            if(idx < 0 || idx >= r || jdy < 0 || jdy >= c){
                continue;
            }
            else if(board[idx][jdy] < target){
                DFS(board, idx, jdy, target);
            }
        }
    }
};