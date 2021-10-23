class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int m = matrix.size(), n = matrix[0].size();
        pq.push({matrix[0][0],0});
        while(--k && !pq.empty()){
            auto p = pq.top();
            pq.pop();
            int i = p.second/n,j = p.second%n;
            if(j+1<n) pq.push({matrix[i][j+1],i*n+j+1});
            if(j==0 && i+1 <m) pq.push({matrix[i+1][0],(i+1)*n});
        }
        return pq.top().first;
    }
};