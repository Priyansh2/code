class Solution {
public:
    int solve(int node, vector<int> &dp, vector<vector<int>> &adj, vector<int> &quiet){
        if(dp[node]!=INT_MAX) return dp[node];
        for(auto c : adj[node]){
            dp[node] = min(dp[node],solve(c,dp,adj,quiet));
        }
        dp[node] = min(dp[node],quiet[node]);
        return dp[node];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {  
        int n = quiet.size();
        unordered_map<int,int> idx;
        for(int i =0;i<n;i++)
        {
            idx[quiet[i]] = i;        
        }
        vector<vector<int>> adj(n);
        for(auto e : richer){
            adj[e[1]].push_back(e[0]);
        }
        vector<int> dp (n,INT_MAX); //store min quiet values;
        vector<int> ans(n);
        for(int i =0;i<n;i++){
            int p = solve(i,dp,adj,quiet);
            ans[i] = idx[p];
        }
        return ans;
    }
};