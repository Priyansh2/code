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
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
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
};