class Solution {
public:
    long long INF = LONG_MAX;
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e : roads){
            adj[e[0]].push_back({e[2],e[1]});
            adj[e[1]].push_back({e[2],e[0]});
            
        }
        vector<long long > dist(n,INF);
        dist[0] = 0;
        multiset<pair<long long,int>> pq;
        pq.insert({0,0});
        vector<int> count(n,0);
        count[0] = 1;
        while(!pq.empty()){
            auto p =*pq.begin();
            pq.erase(pq.begin());
            int u = p.second, d = p.first;
            if(d > dist[u]) continue;
            for(auto & c :adj[u]){
                int v = c.second, wt = c.first;
                if(dist[v] > dist[u] + wt){
                    dist[v]  = dist[u] + wt;
                    count[v]=count[u];
                    pq.insert({dist[v],v});
                }
               else if (dist[v] == dist[u] + wt){
                    count[v]=(count[v] + count[u])%mod;
                }
            }
        }
        return count[n-1];
    }
};