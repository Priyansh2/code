class Solution {
public:
    int INF = 1e9;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int> (n,INF));
        for(auto e : edges){
            dist[e[0]][e[1]] = dist[e[1]][e[0]] = e[2];
            dist[e[0]][e[0]] = dist[e[1]][e[1]] = 0;
        }
        for(int k = 0;k<n;k++){
            for(int i =0;i<n;i++){
                for(int j =0;j<n;j++){
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
        int mine = INT_MAX;
        int node = -1;
        for(int i =0;i<n;i++){
            int cnt=0;
            for(int j =0;j<n;j++){
                if(dist[i][j]<=distanceThreshold)cnt++;
            }
            if(mine  > cnt){
                mine = cnt;
                node = i;
            }
            else if (cnt == mine && node < i){
                node = i;
            }
        }
        return node;
    }
};