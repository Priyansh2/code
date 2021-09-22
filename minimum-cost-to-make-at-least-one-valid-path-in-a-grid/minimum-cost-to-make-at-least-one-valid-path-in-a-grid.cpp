class Solution {
    private:
    int m,n;
    int INF = 1e9;
public:
    int get_index(int i, int j){
        return i*n +j;
    }
    int minCost(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<int> d(m*n,INF);
        d[0] = 0;
        multiset<pair<int,int>>pq;
        pq.insert({0,0});
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!pq.empty()){
            auto p =*pq.begin();
            pq.erase(pq.begin());
            int dist = p.first, u = p.second;
            if(dist > d[u]) continue;
            d[u] = dist;
            int i = u/n , j = u%n;
            for(int k = 0;k<4;k++){
                int x = dir[k][0] + i, y = dir[k][1] + j;
                int id = get_index(x,y);
                if(x<0 || y <0 || x>=m || y>=n) continue;
                int wt = 1;
                if(grid[i][j]-1 == k) wt--;
                if(d[id] > d[u] + wt){
                    d[id] = d[u] + wt;
                    pq.insert({d[id],id});
                }
            }
        }
        int id = get_index(m-1,n-1);
        return d[id];
    }
};