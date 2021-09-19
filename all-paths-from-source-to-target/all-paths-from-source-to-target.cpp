class Solution {
public:
    vector<vector<int>> res;
    vector<bool> vis;
    void solve(int node, int dest, vector<int> temp, vector<vector<int>> &adj){
        vis[node] = true;
        temp.push_back(node);
        if(node == dest){
            res.push_back(temp);
            vis[node] = false;
            return;
        }
        for(auto c : adj[node]){
            if(!vis[c]) solve(c,dest,temp,adj);
        }
        vis[node] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        int n = graph.size();
        vis.resize(n,false);
        solve(0,n-1,temp,graph);
        return res;
    }
};