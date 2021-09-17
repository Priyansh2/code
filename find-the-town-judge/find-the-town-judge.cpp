class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outdeg(n+1);
        vector<unordered_set<int>> adj(n+1);
        
        for(auto e : trust){
            adj[e[0]].insert(e[1]);
            outdeg[e[0]]++;
        }
        int node =0;
        int cnt = 0;
        for(int i =1;i<=n;i++){
            if(outdeg[i]==0) {
                cnt++;
                node = i;
            }
        }
        if(cnt!=1) return -1;
        for(int i =1;i<=n;i++){
            if(node==i) continue;
            if(adj[i].count(node)==0) return -1;
        }
        return node;
    }
};