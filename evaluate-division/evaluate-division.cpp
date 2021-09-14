class dsu{
  public:
    unordered_map<string,pair<string,double>> parent;
    unordered_map<string,int> sz;
    dsu(){
    }
    void init(string s){
        parent[s] = {s,1};
        sz[s] = 1;
        
    }
    pair<string,double> find(string s){
        if(parent.find(s)==parent.end()) return {"",-1};
        if(parent[s].first ==s ) return parent[s];
        auto t = parent[s].second;
        parent[s] = find(parent[s].first);
        parent[s].second*=t;
        return parent[s];
    }
    bool merge(string s1, string s2, double wt){
        s1 = find(s1).first;
        s2 = find(s2).first;
        if(s1==s2) return false;
        if(sz[s1] < sz[s2]) swap(s1,s2);
        parent[s2] = {s1,wt};
        sz[s1]+=sz[s2];
        return true;
        
    }
    
};
class Solution {
public:
    unordered_map<string,unordered_map<string,double>> adj;
    unordered_map<string,bool> vis;
    void dfs(double &p ,string v1, string &v2, double prod){
        if(p!=(double)-1) return;
        vis[v1] = true;
        if(v1==v2){
            p = prod;
            return;
        }
        for(auto it = adj[v1].begin(); it!=adj[v1].end();it++){
            if(vis.find(it->first)==vis.end()) dfs(p,it->first,v2,prod*it->second);
        }
    }
    vector<double> dfs_solve(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){
        int n = values.size();
        for(int i =0;i<n;i++){
            auto v1 = equations[i][0];
            auto v2 = equations[i][1];
            auto wt = values[i];
            adj[v1][v2]= wt;
            adj[v2][v1]=1/wt; 
        }
        vector<double>res;
        for(auto q : queries){
            auto v1 = q[0];
            auto v2 = q[1];
            if(adj.find(v1)==adj.end() || adj.find(v2)==adj.end()){
                res.push_back(-1);
                continue;
            }
            double p = -1;
            vis.clear();
            dfs(p,v1,v2,(double)1);
            res.push_back(p);
        }
        return res;
    }
    vector<double> uf_solve(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){
        int n = equations.size();
        int cnt=0;
        dsu d;
        for(int i =0;i<n;i++){
            auto v1 = equations[i][0];
            auto v2 = equations[i][1];
            auto wt = values[i];
            d.init(v1);
            d.init(v2);
            d.merge(v2,v1,wt);    
        }
        vector<double> res;
        for(auto q : queries)
        {
            auto s1 = q[0], s2 = q[1];
            auto p1 = d.find(s1), p2 = d.find(s2);
            double ans = -1;
            if(p1.second!=-1 && p2.second!=-1){
                if(p1.first==p2.first) ans = p1.second/p2.second;    
            }
            res.push_back(ans);
            
        }
        return res;
        
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        return dfs_solve(equations, values, queries);
        return uf_solve(equations, values, queries);
    }
};