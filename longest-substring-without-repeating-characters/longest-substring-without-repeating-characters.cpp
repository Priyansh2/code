class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) return 0;
        vector<int> prev(n,-1);
        unordered_map<char,int> mp;
        for(int i = 0;i<n;i++){
            if(mp.find(s[i])!=mp.end()) prev[i] = mp[s[i]];
            mp[s[i]] = i;
        }
        vector<int> dp (n);
        dp[0]=1;
        int maxlen = dp[0];
        for(int i = 1;i<n;i++){
            if(prev[i]< i - dp[i-1]) dp[i] = dp[i-1] +1;
            else dp[i] = i-prev[i];
            maxlen = max(maxlen , dp[i]);
        }
        return maxlen;
        
    }
};