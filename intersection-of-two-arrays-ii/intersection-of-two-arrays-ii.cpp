class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;
        vector<int> res;
        for(auto &x : nums1) freq[x]++;
        for(auto &x : nums2){
            if(freq.count(x)==1){
                if(freq[x]-- > 0) res.push_back(x);
            }
        }
        return res;
    }
};