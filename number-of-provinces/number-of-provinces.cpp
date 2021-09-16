class Solution {
public:
    vector<bool> vis;
    void dfs(int node, int parent, vector<vector<int>> &adj){
        vis[node] = true;
        int n = adj.size();
        for(int i = 0;i<n;i++){
            if(adj[node][i] && !vis[i] && i!=parent) dfs(i,node,adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt=  0;
        int n = isConnected.size();
        vis.resize(n,false);
        for(int i =0;i<n;i++){
            if(vis[i]) continue;
            dfs(i,-1,isConnected);
            cnt++;
        }
        return cnt;
    }
};