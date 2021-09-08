class Solution {
public:
    vector<vector<int>> g;
    vector<int> ans;
    vector<int> dfs(int root, int parent,string &label){
        if(g[root].size()==1 && parent!=-1){
            vector<int> temp (26,0);
            temp[label[root]-'a'] = 1;
            ans[root] = 1;
            return temp;
        }
        vector<int> cnt(26,0);
        for(int child : g[root]){
            if(child!=parent){
                auto temp = dfs(child,root,label);
                for(int i =0;i<26;i++) cnt[i]+=temp[i];
            }
        }
        ans[root] = ++cnt[label[root]-'a'];
        return cnt;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        g.resize(n);
        ans.resize(n);
        for(auto e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(0,-1,labels);
        return ans;
        
    }
};