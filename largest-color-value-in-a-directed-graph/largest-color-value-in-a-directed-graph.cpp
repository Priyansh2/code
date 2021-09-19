class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<vector<int>> adj (n);
        vector<int> indeg(n);
        vector<vector<int>> cval(n,vector<int> (26));
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }
        queue<int> q;
        for(int i =0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
                cval[i][colors[i]-'a']++;
            }
        }
        int t = 0;
        while(!q.empty()){
            auto p =q.front();
            t++;
            q.pop();
            for(auto c : adj[p]){
                indeg[c]--;
                for(int j =0;j<26;j++){
                    
                    if(j==colors[c]-'a') cval[c][j] =max(cval[c][j],cval[p][j] +1);
                    else cval[c][j] = max(cval[c][j],cval[p][j]);
                }
                if(indeg[c]==0) q.push(c);
                
            }
        }
        if(t!=n) return -1;
        int ans = INT_MIN;
        for(int i =0;i<n;i++){
            int temp = INT_MIN;
            for(int j = 0;j<26;j++){
                temp = max(temp, cval[i][j]);
            }
            ans = max(ans, temp);
        }
        return ans;
        
        
        
    }
};