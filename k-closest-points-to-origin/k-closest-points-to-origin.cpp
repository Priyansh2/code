class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>,vector<pair<double,int>>, greater<pair<double,int>>> pq;
        int n = points.size();
        for(int i =0;i<n;i++){
            double d = pow(points[i][0],2) + pow(points[i][1],2);
            pq.push({sqrt(d),i});
        }
        vector<vector<int>>res;
        while(k--){
            auto p = pq.top();
            res.push_back(points[p.second]);
            pq.pop();
        }
        return res;
    }
};