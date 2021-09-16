class Solution {
public:
    vector<int> parent;
    vector<int> sz;
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i] = find(parent[i]);
    }
    void merge(int i ,int j){
        i = find(i);
        j = find(j);
        if(i!=j){
            if(sz[i] > sz[j]) swap(i,j);
            parent[i] = j;
            sz[j]+=sz[i];
        }
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.clear();
        sz.clear();
        parent.resize(n+1,-1);
        sz.resize(n+1,1);
        for(int i =1;i<=n;i++) parent[i] = i;
        vector<int> indeg(n+1,0);
        int node=-1;
        for(auto edge: edges){
            indeg[edge[1]]++;
            if(indeg[edge[1]]==2){
                node = edge[1];
            }
        }
        if(node==-1){
            //normal dsu
            for(auto edge: edges){
                if(find(edge[0])==find(edge[1])) return edge;
                merge(edge[0],edge[1]);
            }
        }
        else{
            //special case
            for(auto edge: edges){
                if(edge[1]==node) continue;
                merge(edge[0],edge[1]);
            }
            for(auto edge: edges){
                if(edge[1]!=node) continue;
                if(find(edge[0])==find(edge[1])) return edge;
                merge(edge[0],edge[1]);
            }
        }
        return edges.back();
    }
};