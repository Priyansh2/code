class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<bool> vis;
    int res;
    long long  INF = LONG_MAX;
    vector<long long > dist;
    int mod = 1e9+7;
    void dfs(int node, int parent){
        if(parent!=-1 && dist[node] <= dist[parent]) return;
        if(node == 0 && parent!=-1){
            res = (res + 1)%mod;
            return;
        }
        for(auto & [v,wt] : adj[node]){
            if(parent ==v) continue;
            if(!vis[v]){
                vis[v] = true;
                dfs(v,node);
                vis[v] = false;
            }
        }
         
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        if(n==1) return 0;
        adj.resize(n);
        vis.resize(n);
        for(auto &e : edges){
            e[0]--;
            e[1]--;
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        dist.resize(n,INF);
        dist[n-1] = 0;
        multiset<pair<long long,int>> pq;
        vector<int> count(n,0);
        count[n-1] = 1;
        pq.insert({0,n-1});
        while(!pq.empty()){
            auto p =  *pq.begin();
            pq.erase(pq.begin());
            long long d = p.first, u = p.second;
            if(d > dist[u]) continue;
            for(auto &[v,wt] : adj[u]){
                long long  cost = wt + dist[u];
                if(dist[v]  > cost){
                    dist[v] = cost;
                    pq.insert({dist[v],v});
                }
                if(dist[v] > dist[u]){
                    count[v]=(count[v] + count[u])%mod;
                }
            }
        }
        return count[0];
        //res = 0;
        //vis[n-1] = true;
        //dfs(n-1,-1);
        //return res;
        
    }
};