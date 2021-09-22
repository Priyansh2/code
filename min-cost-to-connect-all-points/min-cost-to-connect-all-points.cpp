class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<bool> vis;
    multiset<pair<int,int>> pq;
    int solve(int v){
        pq.insert({0,v});
        int mincost = 0;
        while(!pq.empty()){
            auto p = *pq.begin();
            pq.erase(pq.begin());
            if(vis[p.second]) continue;
            vis[p.second] = true;
            mincost+=p.first;
            int u = p.second;
            for(auto c : adj[u]){
                if(!vis[c.second]){
                    pq.insert({c.first,c.second});
                }
            }
        }
        return mincost;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        adj.resize(n);
        vis.resize(n,false);
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({cost,j});
                adj[j].push_back({cost,i});
            }
        }
        auto mincost = solve(0);
        return mincost;
    }
};