class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        queue <int> q;
        for(int i =0;i<n;i++) {
            if(board[0][i]=='O') {
                q.push(i);
            }
            if(board[m-1][i]=='O') {
                q.push((m-1)*n + i);
            }
            
        }
        for(int i =0;i<m;i++){
            if(board[i][0]=='O') {
                q.push(i*n + 0);
            }
            if(board[i][n-1]=='O') {
                q.push(i*n + n-1);
            }
        }
        auto grid = board;
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            auto p =q.front();
            q.pop();
            int a = p/n;
            int b = p%n;
            grid[a][b] = '?';
            for(auto d : dir){
                int x = d.first + a, y = d.second + b;
                int id = x*n + y;
                if(x < 0 || y < 0 || y >= n || x >= m) continue;
                if(grid[x][y]=='O'){
                    q.push(id);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++) if(grid[i][j]=='O') grid[i][j]='X';
            
        }
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++) if(grid[i][j]=='?') grid[i][j] = 'O';
        }
        board = grid;
        return;
    }
};