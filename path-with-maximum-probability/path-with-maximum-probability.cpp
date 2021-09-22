class Solution {
public:
    double INF = 1e9;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double,int>>> adj (n);
        int i=0;
        for(auto &e : edges){
            auto wt = succProb[i];
            adj[e[0]].push_back({-1*log10(wt),e[1]});
            adj[e[1]].push_back({-1*log10(wt),e[0]});
            i++;
        }
        vector<double> dist(n,INF);
        dist[start] = 0.0;
        multiset<pair<double,int>> pq;
        pq.insert({0.0,start});
        while(!pq.empty()){
            auto p = *pq.begin();
            pq.erase(pq.begin());
            if(p.first > dist[p.second]) continue;
            int u = p.second;
            for(auto &c : adj[u]){
                int v  = c.second;
                double wt = c.first;
                if(dist[v] > dist[u] + wt){
                    dist[v] = dist[u] + wt;
                    pq.insert({dist[v],v});
                }
            }
        }
        return dist[end] == INF ? 0.0 : pow(10,-dist[end]);
        
    }
};