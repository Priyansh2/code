class dsu{
  public:
    unordered_map<int,int> parent;
    unordered_map<int,int> sz;
    unordered_map<int,int> rk;
    dsu(){
    }
    void init(int i ){
        sz[i] = 1;
        rk[i] = 0;
        parent[i] = i;
    }
    int find(int i){
        if(parent[i]==i) return i;
        return parent[i] = find(parent[i]);
    }
    int get_size(int i){
        return sz[find(i)];
    }
    bool merge(int i, int j){
        i = find(i);
        j = find(j);
        if(i==j) return false;
        if(rk[i] < rk[j]) swap(i,j);
        parent[j] = i;
        if(rk[i]==rk[j]) rk[i]++;
        sz[i]+=sz[j];
        return true;
    }
};
class Solution {
public:
    int m = 1e4+5;
    int get_index(int i , int j){
        return i*m +j;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        dsu d;
        for(int i = 0;i<n;i++){
            d.init(stones[i][0]);
            d.init(stones[i][1] + m);
        }
        for(int i =0;i<n;i++) d.merge(stones[i][0],stones[i][1] + m);
        unordered_set<int> st;
        for(int i =0;i<n;i++){
            st.insert(d.find(stones[i][0]));
        }
        return n - st.size();
        
        /*unordered_map<int,vector<vector<int>>> x_cor,y_cor;
        for(auto s : stones){
            int id = get_index(s[0],s[1]);
            d.init(id);
            x_cor[s[0]].push_back(s);
            y_cor[s[1]].push_back(s);
        }
        
        for(auto x : x_cor){
            auto v = x.second;
            if(v.size()==1) continue;
            auto first = get_index(v[0][0],v[0][1]);
            for(int i =1;i<v.size();i++){
                int id = get_index(v[i][0],v[i][1]);
                d.merge(first,id);
            }
        }
        for(auto y : y_cor){
            auto v = y.second;
            if(v.size()==1) continue;
            auto first = get_index(v[0][0],v[0][1]);
            for(int i =1;i<v.size();i++){
                int id = get_index(v[i][0],v[i][1]);
                d.merge(first,id);
            }
        }
        unordered_set<int> compo;
        int sum=0;
        for(int i =0;i<n;i++){
            int id =get_index(stones[i][0],stones[i][1]);
            auto p = d.get_size(id);
            if(compo.count(d.parent[id])==0 && p>1){
                sum+=p-1;
                compo.insert(d.parent[id]);
            }
        }
        return sum;*/
        
    }
};