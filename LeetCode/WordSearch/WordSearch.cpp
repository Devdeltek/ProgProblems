class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int r;
    int c;
    string::iterator last;
    bool check = false;
    vector<vector<int>> visited;

    bool exist(vector<vector<char>>& board, string word) {
        string::iterator it;
        last = word.end();
        r = board.size();
        c = board[0].size();
        vector<int> setup(c);
    
        for(int i = 0; i < r; i++){
            visited.push_back(setup);
        }
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(board[i][j] == word[0]){
                    for(int k = 0; k < r; k++){
                        for(int l = 0;  l < c; l++){
                            visited[k][l] = 0;
                        }
                    }
                    it = word.begin();
                    it++;
                    DFS(board, i, j, it);
                    if(check){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    void DFS(vector<vector<char>>& board, int i, int j, string::iterator it){
        if(visited[i][j] == 1){
            return;
        }
        if(last == it){
            check = true;
            return;
        }

        visited[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int idx = i + dx[k];
            int jdy = j + dy[k];
            if(idx < 0 || idx >= r || jdy < 0 || jdy >= c){
                continue;
            }
            else if(board[idx][jdy] == *it && visited[idx][jdy] != 1){
                DFS(board, idx, jdy, it+1);
                visited[idx][jdy] = 0;
            }
        }
    }
};