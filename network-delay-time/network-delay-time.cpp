class Solution {
public:
    int INF = 1e9;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj (n+1);
        for(auto e : times){
            adj[e[0]].push_back({e[2],e[1]});
        }
        vector<int> dist(n+1,INF);
        dist[k] = 0;
        multiset<pair<int,int>> pq;
        pq.insert({0,k});
        while(!pq.empty()){
            auto p = *pq.begin();
            pq.erase(pq.begin());
            if(p.first  > dist[p.second]) continue;
            int u = p.second;
            for(auto c : adj[u]){
                int v = c.second, wt = c.first;
                if(dist[v] > dist[u] + wt){
                    dist[v] = dist[u] +wt;
                    pq.insert({dist[v],v});
                }
            }
        }
        int maxtime = INT_MIN;
        for(int i =1;i<=n;i++){
            maxtime = max(maxtime, dist[i]);
        }
        return maxtime ==INF ? -1 : maxtime; 
    }
};