class Solution {
    int m,n;
    vector<vector<int>> grid;
    public:
    bool check(vector<int> &p){
        int i = p[0], j=  p[1];
        return i>=0 && j>=0 && i<=m-1 && j<=n-1 && grid[i][j]==1;
    }
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        m = n = N;
        grid.resize(m,vector<int>(n,1));
        for(auto &p : mines) grid[p[0]][p[1]] = 0;
        int maxorder = 0;
        /*for(int i= 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==0) continue;
                int order = 1;
                vector<int> left = {i,j-1};
                vector<int> right = {i,j+1};
                vector<int> up = {i-1,j};
                vector<int> down = {i+1,j};
                while(check(left) && check(right) && check(up) && check(down)){
                    left[1]--;
                    right[1]++;
                    up[0]--;
                    down[0]++;
                    order++;
                }
                maxorder = max(maxorder,order);
            }
        }*/
        auto left = grid, right = grid, up = grid, down = grid;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==0) continue;
                if(j-1>=0) left[i][j] = 1 + left[i][j-1];
                if(i-1>=0) up[i][j] = 1 + up[i-1][j];
            }
        }
        for(int i = m-1;i>=0;i--){
            for(int j =n-1;j>=0;j--){
                if(grid[i][j]==0) continue;
                if(j+1 < n) right[i][j] = 1 + right[i][j+1];
                if(i+1 < m) down[i][j] = 1 + down[i+1][j];
            }
        }
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                int res = min(left[i][j],right[i][j]);
                res = min(res,up[i][j]);
                res = min(res, down[i][j]);
                maxorder = max(maxorder,res);
            }
        }
        
        return maxorder;
    }
};