class Solution {
public:
    vector<vector<int>> adj;
    int maxd;
    int A;
    unordered_map<int,int> par;
    void dfs(int node, int parent, int d, bool is_par = false){
        if(maxd < d){
            maxd = d;
            A = node;
        }
        if(is_par) par[node] = parent;
        for(auto c : adj[node]){
            if(parent!=c) dfs(c,node,d+1,is_par);
        }
        
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            
        }
        maxd = INT_MIN;
        A= -1;
        dfs(0,-1,0);
        int t = A;
        A = -1;
        maxd = INT_MIN; //edges
        dfs(t,-1,0,true);
        int c = 0;
        while(c !=maxd/2){
            A = par[A];
            c++;
        }
        if(maxd & 1) return {A, par[A]};
        return {A};
        
    }
};