class Solution {
public:
    vector<vector<int>> g;
    vector<bool> vis;
    bool dfs(int i){
        if(vis[i]) return false;
        vis[i] = true;
        for(auto x : g[i]){
            if(!dfs(x)) return false;
            
        }
        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        g.resize(n);
        vis.resize(n,false);
        vector<int> indeg(n,0);
        for(int i =0;i<n;i++){
            if(leftChild[i]!=-1)
            {
                g[i].push_back(leftChild[i]);
                indeg[leftChild[i]]++;   
            }
            if(rightChild[i]!=-1)
            {
                g[i].push_back(rightChild[i]);
                indeg[rightChild[i]]++;
            }
        }
        int cnt=0;
        int root=-1;
        for(int i =0;i<n;i++){
            if(indeg[i]==0) {
                root = i;
                cnt++;
            }
            if(cnt > 1) return false;
        }
        if(root==-1) return false; 
        if(!dfs(root)) return false;
        for(int i =0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;
        
    }
};