class Solution {
public:
    int numTrees(int n) {
        //dp[j] = sum(dp[i]*dp[j-1-i]) 0<=i<j;
        //dp[0] = 1;
        //ans: dp[n];
        vector<int> dp (n+1);
        dp[0] =1;
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<i;j++){
                dp[i]+=dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
    }
};