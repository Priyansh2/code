class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int cnt = 0;
        for(int i =0;i<n;i++){
            int sum1 = nums[i] + k;
            int sum2 = nums[i] - k;
            if(mp.count(sum1)==1)cnt+=mp[sum1];
            if(mp.count(sum2)==1)cnt+=mp[sum2];
            mp[nums[i]]++;
        }
        return cnt;
        
    }
};