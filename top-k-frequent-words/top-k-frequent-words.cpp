class Solution {
public:
    static bool compare(pair<int,string> &p1, pair<int,string> &p2){
        return p1.first!=p2.first ? p1.first < p2.first : p1.second > p2.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>, vector<pair<int,string>> , decltype(&compare)> pq(compare);
        unordered_map<string,int> mp;
        for(auto &s : words) mp[s]++;
        for(auto &it : mp) pq.push({it.second, it.first});
        vector<string> res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};