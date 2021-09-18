class dsu{
  public:
    vector<int> parent;
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
    string smallest;
    unordered_set<string> vis;
    void dfs(string s, vector<vector<int>> &pairs){
        vis.insert(s);
        cout <<s << " ";
        if(smallest!="" && smallest  > s) smallest = s;
        else if(smallest=="")smallest = s;
        for(auto p : pairs){
            auto temp = s;
            swap(temp[p[0]],temp[p[1]]);
            //cout <<"sasa:"<<" "<<temp<<endl;
            if(vis.count(temp)==1) continue;
            dfs(temp,pairs);
        }
    }
    void solve(string s,vector<vector<int>> &pairs){
        dsu uf(s.length());
        int n =s.length();
        for(auto p : pairs){
            uf.merge(p[0],p[1]);
        }
        smallest = s;
        map<int,vector<int>> mp;
        for(int i =0;i<n;i++){
            mp[uf.find(i)].push_back(i);
        }
        for(auto &[x,pos] : mp){
            string temp;
            for(auto p : pos){
                temp+=s[p]; 
            }
            sort(temp.begin(),temp.end());
            int i =0;
            for(auto p : pos) smallest[p] = temp[i++];
        }
        
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        //dfs(s,pairs); //O(p^factorial(|s|))
        solve(s,pairs);
        return smallest;
    }
};