class dsu{
  public:
    vector<int> parent;
    vector<int> sz;
    dsu(int n){
        for(int i =0;i<n;i++){
            parent.push_back(i);
            sz.push_back(1);
        }
    }
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i] = find(parent[i]);
    }
    bool merge(int i ,int j){
        i = find(i);
        j = find(j);
        if(i==j) return false;
        if(sz[i] < sz[j]) swap(i,j);
        parent[j] = i;
        sz[i]+=sz[j];
        return true;
    }
    
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        unordered_map<int,unordered_map<int,int>> mp;
        int n =source.size();
        dsu uf(n);
        for(auto p : allowedSwaps){
            uf.merge(p[0],p[1]);
        }
        int cnt= 0;
        for(int i =0;i<n;i++){
            mp[uf.find(i)][source[i]]++;
        }
        for(int i =0;i<n;i++){
            auto p =uf.parent[i];
            if(mp[p][target[i]]<=0) cnt++;
            else mp[p][target[i]]--;
        }
        return cnt;
        
    }
};