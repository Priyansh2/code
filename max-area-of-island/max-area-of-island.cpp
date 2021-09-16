class Solution {
public:
    void dfs(int i, int j ,vector<vector<int>> &grid, int &cnt){
        cnt++;
        grid[i][j] = 0;
        //cout <<cnt << " "<< i << " "<<j << "sasa"<<endl;
        int m= grid.size(), n=  grid[0].size();
        vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        for(auto d: dir){
            int x = d[0] + i, y = d[1] + j;
            if(x <0 || y <0 || x>=m || y >=n) continue;
            if(grid[x][y]==0) continue;
            //cout <<"s: "<< grid[x][y] << " " << x << " "<<y << endl;
            grid[x][y] = 0;
            dfs(x,y,grid,cnt);
            
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==1){
                    int cnt =0;
                    dfs(i,j,grid,cnt);
                    //cout <<cnt << endl;
                    res = max(res,cnt);
                }
            }
        }
        return res;
    }
};