class dsu{
  public:
    vector<int>parent;
    vector<int> sz;
    dsu(int n){
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        sz.resize(n,1);
    }
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i] = find(parent[i]);
    }
    bool merge(int i, int j){
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
    bool overlap(vector<int> &p1, vector<int>&p2){
        int left = max(p1[0],p2[0]), right = min(p1[1],p2[1]);
        return left<=right;
    }
    vector<vector<int>> solve1(vector<vector<int>> &ints, vector<int> &p){
        ints.push_back(p);
        int n = ints.size();
        dsu uf(n);
        for(int i =0;i<n;i++){
            if(overlap(ints[i],p)) {
                uf.merge(i,n-1);
            }
        }
        map<vector<int>,vector<int>>mp;
        vector<vector<int>>res;
        for(int i =0;i<n;i++){
            int j = uf.find(i);
            auto p1 = ints[j] , p2 = ints[i];
            if(mp.count(ints[j])==1) p1 = mp[ints[j]];
            int left = min(p1[0],p2[0]), right = max(p1[1],p2[1]);
            mp[ints[j]] = {left,right};
        }
        for(auto &it : mp){
            res.push_back(it.second);
        }
        return res;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        return solve1(intervals,newInterval);  
    }
};