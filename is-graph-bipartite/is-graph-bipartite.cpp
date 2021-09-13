class Solution {
public:
    vector<int> color;
    bool dfs(int node,vector<vector<int>> &adj, int parent){
        if(parent == -1 ) color[node] = 0;
        else color[node] = 1 - color[parent];
        for(auto c : adj[node]){
            if(c==parent) continue;
            if(color[c]!=-1 && color[c]==color[node]) return false;
            if(color[c]==-1 && !dfs(c,adj,node)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color.resize(n,-1);
        for(int i =0;i<n;i++){
            if(color[i]==-1 && !dfs(i,graph,-1)) return false;
        }
        return true;
    }
};