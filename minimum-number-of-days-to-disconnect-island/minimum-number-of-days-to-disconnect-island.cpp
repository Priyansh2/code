class Solution {
    private:
    int m,n;
public:
    
    vector<bool> vis;
    bool isap = false;
    vector<int> intime,lowtime;
    int time_cnt = 0;
    int c_one;
    void dfs(int node, int parent, vector<vector<int>> &grid){
        vis[node] = true;
        intime[node] = time_cnt++;
        lowtime[node] = intime[node];
        int kids = 0;
        int i = node/n, j = node%n;
        vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        c_one++;
        for(auto d : dir){
            int x = d[0] + i, y = d[1] + j;
            int child = x*n+y;
            if(x < 0 || y <0 || x >=m || y>=n) continue;
            if(grid[x][y]==0 || child==parent) continue;
            if(vis[child]){
                lowtime[node] = min(lowtime[node],intime[child]);
            }
            else{
                kids++;
                dfs(child,node, grid);
                lowtime[node] = min(lowtime[node],lowtime[child]);
                if(parent!=-1 && lowtime[child] >= intime[node]){
                    isap = true;
                }
            }
            
        }
        if(parent==-1 && kids > 1) isap = true;
    }
    
    int minDays(vector<vector<int>>& grid) {
        int cnt = 0;
        c_one = 0;
        m = grid.size(), n = grid[0].size();
        intime.resize(m*n,0);
        lowtime.resize(m*n,0);
        vis.resize(m*n,false);
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                int id = i*n+j;
                if(grid[i][j]==1 && !vis[id]){
                    
                    dfs(id,-1,grid);
                    cnt++;
                }
                if(cnt>1){
                    break;
                }
            }
            if(cnt > 1) break;
        }
        if(cnt!=1) return 0;
        if(cnt==1 && isap) return 1;
        if(c_one==1) return 1;
        return 2;
        
    }
};