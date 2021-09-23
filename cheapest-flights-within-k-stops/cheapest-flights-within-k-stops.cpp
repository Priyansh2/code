class Solution {
public:
    int INF = 1e9;
    int solve1(int n, vector<vector<int>>&flights, int src, int dst, int k){
        vector<vector<pair<int,int>>> adj(n);
        for(auto & e : flights){
            adj[e[0]].push_back({e[1],e[2]});
        }
        vector<vector<int>> dp(n,vector<int>(k+1,INF));
        for(int i =0;i<=k;i++) dp[src][i] = 0;
        for(auto &[j,c] : adj[src]){
                dp[j][0] = c;
        }
        
        for(int l = 1;l<=k;l++){
            for(int i =0;i<n;i++){
                for(auto &[j,c] : adj[i]){
                    dp[j][l] = min(dp[j][l],dp[i][l-1] + c);
                }
            }
        }
        return dp[dst][k]== INF ? -1:dp[dst][k];
    }
    int solve2(int n, vector<vector<int>>&flights, int src, int dst, int k){
        vector<vector<int>> dp(n,vector<int>(k+1,INF));
        for(int i =0;i<=k;i++) dp[src][i] = 0;
        for(auto &e : flights){
            if(e[0]==src) dp[e[1]][0] = e[2];
        }
        for(int l = 1;l<=k;l++){
            for(auto &e : flights){
                dp[e[1]][l] = min(dp[e[1]][l],dp[e[0]][l-1] + e[2]);
            }
        }
        return dp[dst][k]== INF ? -1:dp[dst][k];
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //return solve1(n,flights,src,dst,k);
        return solve2(n,flights,src,dst,k);
        
    }
};