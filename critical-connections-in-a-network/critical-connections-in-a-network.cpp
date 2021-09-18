class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<vector<int>> res;
    vector<int> intime, lowtime;
    int time_cnt;
    void dfs(int node, int parent){
        vis[node]=true;
        intime[node] = time_cnt++;
        lowtime[node] = intime[node];
        for(auto c : adj[node]){
            if(c == parent) continue;
            if(vis[c]){
                lowtime[node] = min(lowtime[node],intime[c]);
            }
            else{
                dfs(c,node);
                lowtime[node] = min(lowtime[node],lowtime[c]);
                if(lowtime[c] > intime[node]){
                    //edge (node,c) is bridge
                    res.push_back({node,c});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        res.clear();
        time_cnt = 0;
        adj.resize(n);
        vis.resize(n,false);
        intime.resize(n);
        lowtime.resize(n);
        for(auto e : connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i =0;i<n;i++){
            if(vis[i]) continue;
            dfs(i,-1);
        }
        return res;
        
    }
};