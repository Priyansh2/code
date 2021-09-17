class Solution {
public:
    bool check(int i, int j, int m, int n, vector<vector<int>> &grid){
        return i>=0 && j>=0 && i<=m-1 && j<=n-1 && grid[i][j]==1;
    }
    void bfs(int i, int j, vector<vector<int>> &land , vector<int> &end){
        land[i][j] = 0;
        queue<int> q;
        int m = land.size(), n = land[0].size();
        q.push(i*n +j);
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            i = p/n;
            j = p%n;
            vector<vector<int>> dir = {{1,0,0},{0,1,1},{-1,0,2},{0,-1,3}};
            bool fl = false;
            for(auto d : dir){
                int x = d[0] + i, y = d[1] + j;
                if(!check(x,y,m,n,land)) continue;
                fl = true;
                land[x][y] = 0;
                q.push(x*n + y);
            }
            if(!fl && q.size() == 0) end = {i,j};
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        int m = land.size(), n = land[0].size();
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(land[i][j]==0) continue;
                vector<int> end;
                //bfs(i,j,land,end); //TLE
                int a = i;
                while(a < m && land[a][j]==1){
                    a++;
                }
                a--;
                int b = j;
                while(b<n && land[a][b]==1){
                    b++;
                }
                b--;
                res.push_back({i,j,a,b});
                //res.push_back({i,j,end[0],end[1]});
                for(int k = i;k<=a;k++){
                    for(int l =j;l<=b;l++) land[k][l]= 0;
                }
            }
        }
        return res;
    }
};