class Solution {
public:
    void bfs(vector<bool> &vis, vector<vector<int>> &ht, queue <int> &q){
        int m = ht.size(), n = ht[0].size();
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int  i = p/n;
            int j = p%n;
            vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
            for(auto d : dir){
                int x = i + d.first, y = j + d.second;
                int id = x*n + y;
                if(x<0 || y< 0 || x>=m || y>=n) continue;
                if(!vis[id] && ht[x][y] >= ht[i][j]){
                    vis[id] = true;
                    q.push(id);
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int m = heights.size(), n = heights[0].size();
        vector<bool> v1,v2;
        v1.resize(m*n,false);
        v2.resize(m*n,false);
        queue<int> q1,q2;
        for(int i =0;i<n;i++){
            q1.push(i);
            v1[i] = true;
            q2.push((m-1)*n + i);
            v2[(m-1)*n +i] = true;
        }
        for(int i=1;i<m;i++){
            q1.push(i*n);
            v1[i*n] = true;
            q2.push((m-1-i)*n+n-1);
            v2[(m-1-i)*n +n-1] = true;
        }
        bfs(v1,heights,q1);
        bfs(v2,heights,q2);
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                int id = i*n +j;
                if(v1[id] && v2[id]) res.push_back({i,j});
            }
        }
        return res;
        
        
    }
};