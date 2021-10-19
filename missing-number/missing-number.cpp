class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*int res = 0;
        for(auto &x : nums) res^=x;
        for(int i =0;i<=nums.size();i++) res^=i;
        return res;*/
        sort(nums.begin(),nums.end());
        int low = 0, high = nums.size();
        int ans = -1;
        while(low <=high){
            int mid = low + (high - low)/2;
            if(mid >= nums.size() || mid < 0 || nums[mid] > mid) {
                ans = mid;
                high = mid-1;
            }
            else low = mid +1;
        }
        return ans;
    }
};