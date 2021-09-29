class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int,int> mp; 
        mp[0] = 1;
        int n = nums.size();
        int cnt=0;
        for(int i =0;i<n;i++){
            sum=(sum + nums[i])%k;
            if(sum < 0) sum=(sum + k)%k;
            if(mp.find(sum)!=mp.end()){
                cnt+=mp[sum];
            }
            mp[sum]++;
        }
        return cnt;
    }
};