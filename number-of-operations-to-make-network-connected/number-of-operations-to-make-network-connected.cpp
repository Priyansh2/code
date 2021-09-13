class dsu{
    public:
    vector<int> parent;
    vector<int> sz;
    int component;
    dsu(int n){
        parent.resize(n,-1);
        sz.resize(n,1);
        component = n;
    }
    void init(int s){
        parent[s] = s;
    }
    int find(int s){
        if(parent[s]==s) return s;
        return parent[s] = find(parent[s]);
    }
    bool merge(int i, int j){
        i = find(i);
        j = find(j);
        if(i==j) return false;
        if(sz[i] < sz[j]) swap(i,j);
        parent[j] = i;
        sz[i]+=sz[j];
        component--;
        return true;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        dsu d(n);
        int cnt=0;
        for(int i =0;i<n;i++) d.init(i);
        for(auto e : connections){
            int v1 = e[0], v2 = e[1];
            if(!d.merge(v1,v2)) cnt++;
            else d.merge(v1,v2);
        }
        return cnt >= d.component-1 ? d.component-1 : -1; 
    }
};