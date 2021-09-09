class TreeAncestor {
public:
    vector<vector<int>> dp;
    int l;
    TreeAncestor(int n, vector<int>& parent) {
        l = ceil(log2(n));
        dp.resize(n,vector<int>(l+1,-1));
        for(int i =0;i<n;i++) dp[i][0] = parent[i];
        for(int j = 1;j<=l;j++){
            for(int i=0;i<n;i++){
                if(dp[i][j-1]!=-1) dp[i][j] = dp[dp[i][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=log2(k);i>=0 && node!=-1;i--){
            if(k>=(1<<i)){
                node = dp[node][i];
                k=k-(1<<i);
            }
            
        }
        return node;
        
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */