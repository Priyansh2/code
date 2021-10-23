class Solution {
public:
    inline static vector<int>nums1, nums2;
    static bool compare(pair<int,int> &p1, pair<int,int> &p2){
        return nums1[p1.first] + nums2[p1.second] > nums1[p2.first] + nums2[p2.second];
    }
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        this->nums1 = nums1, this->nums2 = nums2;
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(&compare)> pq(compare);
        int n= nums1.size();
        for(int i= 0;i<min(n,k);i++) pq.push({i,0});
        vector<vector<int>> res;
        while(k-- && !pq.empty()){
            auto p = pq.top();
            pq.pop();
            res.push_back({nums1[p.first],nums2[p.second]});
            if(p.second < nums2.size()-1){
                pq.push({p.first,p.second +1});
            }
        }
        return res;
    }
};