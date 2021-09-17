class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<int> q;
        bool fl = false;
        int m = grid.size(), n = grid[0].size();
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==2) q.push(i*n + j);
                if(grid[i][j]==1) fl = true;
            }
        }
        if(!fl) return 0;
        if(q.empty()) return -1;
        int lvl = 0;
        while(!q.empty()){
            int l = q.size();
            while(l--){
                auto p = q.front();
                int i = p/n,j=p%n;
                q.pop();
                vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
                for(auto d : dir){
                    int x = d[0] + i, y = d[1] + j;
                    if(x <0 || y <0 || x>=m || y>=n) continue;
                    if(grid[x][y]!=1) continue;
                    grid[x][y] = 2;
                    q.push(x*n +y);
                }
            }
            lvl++;
        }
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++) if(grid[i][j]==1) return -1;
        }
        return lvl-1;
    }
};