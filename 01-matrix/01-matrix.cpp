class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size() , n = matrix[0].size();
        vector<vector<int>> dist(m,vector<int>(n,0));
        queue <int> q;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(matrix[i][j]==0) q.push(i * n + j);
            }
        }
        vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int i = p/n;
            int j=  p%n;
            for(auto d : dir){
                int x = d[0] + i, y = d[1] + j;
                if(x < 0 || y <0 || x >=m || y >=n) continue;
                if(matrix[x][y]==0) continue;
                dist[x][y] = dist[i][j] + 1;
                matrix[x][y] = 0;
                q.push(x*n +y);
            }
        }
        return dist;
    }
};