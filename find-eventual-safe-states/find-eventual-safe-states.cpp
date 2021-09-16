class Solution {
public:
    vector<int> color;
    vector<int>parent;
    unordered_map<int,bool> unsafe;
    int n;
    void dfs(int i, vector<vector<int>>&g){
        color[i]=1;
        for(int child:g[i]){
            if(color[child]==0){
                parent[child] = i;
                dfs(child,g);
            }
            if(color[child]==2 && unsafe.find(child)!=unsafe.end()){
                   unsafe[i] = true;
            }
            if(color[child]==1){
                int start = child;
                int end = i;
                int j = end;
                unsafe[start] = unsafe[end] = true; //optimization step
                /*unsafe[j] = true;
                while(j!=start){
                    j = parent[j];
                    unsafe[j] = true;
                }*/ 
            }
            
        }
        color[i]=2;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        n =graph.size();
        unsafe.clear();
        color.clear();
        parent.clear();
    
        color.resize(n);
        parent.resize(n,-1);   
        for(int i =0;i<n;i++){
            if(color[i]!=0) continue;
            dfs(i,graph);
            
        }
        vector<int> res;
        for(int i =0;i<n;i++){
            if(unsafe.find(i)==unsafe.end()) res.push_back(i);
        }
        return res;
        
    }
};