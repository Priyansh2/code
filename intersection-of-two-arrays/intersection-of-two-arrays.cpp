class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(),nums1.end());
        vector<int> res;
        for(auto &x : nums2){
            if(st.count(x)==1){
                res.push_back(x);
                st.erase(st.find(x));
            }
        }
        return res;
    }
};