class Solution {
public:
    vector<vector<int>> adj;
    pair<bool,int> dfs(int node, int parent, vector<bool> &apple){
        int sum = 0;
        bool fl = false;
        for(auto c : adj[node]){
            if(c==parent) continue;
            auto p = dfs(c,node,apple);
            if(p.first) {
                sum+=p.second + 2;
                fl = true;
            }
        }
        if(apple[node]){
            fl = true;
        }
        
        return {fl,sum};
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj.resize(n);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return dfs(0,-1,hasApple).second;
    }
};