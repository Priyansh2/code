class node{
  public:
    string name;
    set<string> emails;
    node(vector<string> acc){
        name = acc[0];
        emails.insert(acc.begin()+1,acc.end());
    }
};
class Solution {
public:
    vector<int> parent;
    vector<int> sz;
    int find(int i ){
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n,-1);
        sz.resize(n,1);
        unordered_map<int,node*> acc;
        unordered_map<string, int> ea_link;
        for(int i =0;i<n;i++){
            acc[i] = new node(accounts[i]);
            parent[i] = i;
            for(int j =1;j<accounts[i].size();j++){
                auto email = accounts[i][j];
                if(ea_link.count(email)==0){
                    ea_link[email] = i;
                }
                else{
                    merge(ea_link[email],i);
                }
            }
        }
        unordered_set<int> leaders;
        for(int i =0;i<n;i++){
            int leader = find(i);
            acc[leader]->emails.insert(acc[i]->emails.begin(),acc[i]->emails.end());
            leaders.insert(leader);
        }
        vector<vector<string>> res;
        for(auto & leader : leaders){
            vector<string> t = {acc[leader]->name};
            vector<string> temp (acc[leader]->emails.begin(),acc[leader]->emails.end());
            t.insert(t.end(),temp.begin(),temp.end());
            res.push_back(t);
        }
        return res;
        
    }
};