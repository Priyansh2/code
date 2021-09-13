class Solution {
public:
    vector<int> color;
    vector<vector<int>> adj;
    bool dfs(int node, int parent){
        if(parent==0) color[node] = 0;
        else color[node] = 1 - color[parent];
        for(auto c : adj[node]){
            if(c==parent) continue;
            if(color[c]!=-1 && color[c]==color[node]) return false;
            if(color[c]==-1 && !dfs(c,node)) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        color.resize(n+1,-1);
        adj.resize(n+1);
        for(auto e : dislikes){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i =1;i<=n;i++){
            if(color[i]!=-1) continue;
            if(!dfs(i,0)) return false;
        }
        return true;
        
    }
};