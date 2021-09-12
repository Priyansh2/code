class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto x : nums) freq[x]++;
        priority_queue<pair<int,int>> pq;
        for(auto &[x,y] : freq){
            pq.push({y,x});
        }
        vector<int> res;
        while(!pq.empty() && k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};