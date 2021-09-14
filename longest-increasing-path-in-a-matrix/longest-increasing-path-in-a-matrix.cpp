class Solution {
public:
    vector<int> dp;
    int solve(int i, int j, vector<vector<int>> &matrix){
        int m = matrix.size(), n = matrix[0].size();
        if(dp[i*n + j]!=INT_MIN) return dp[i*n + j];
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        int ans = 0;
        for(auto d : dir){
            int x = d.first + i, y = d.second + j;
            if(x<0 || y < 0 || x>=m || y>=n) continue;    
            if(matrix[x][y] > matrix[i][j]) ans = max(ans, solve(x,y,matrix));
        }
        return dp[i*n + j] = ans + 1;
    }
    int solve_dp(vector<vector<int>> &matrix){
        int m = matrix.size(), n = matrix[0].size();
        int maxlen =INT_MIN;
        dp.resize(m*n,INT_MIN);
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                int len = solve(i,j,matrix);
                maxlen = max(maxlen , len);
                    
            }
        }
        return maxlen;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        return solve_dp(matrix);
    }
};