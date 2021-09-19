class Solution {
public:
    vector<unordered_set<int>> adj;
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        adj.clear();
        adj.resize(n);
        vector<int> indeg(n,0);
        vector<unordered_set<int>> parent(n);
        for(auto edge : prerequisites){
            adj[edge[0]].insert(edge[1]);
            indeg[edge[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            auto p =q.front();
            q.pop();
            for(auto &ch : adj[p]){
                indeg[ch]--;
                parent[ch].insert(parent[p].begin(),parent[p].end());
                parent[ch].insert(p);
                if(indeg[ch]==0) q.push(ch);
            }
        }
        vector<bool> res;    
        for(auto q : queries){
            if(parent[q[1]].find(q[0])!=parent[q[1]].end()) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};