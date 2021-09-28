class Solution {
public:
    void sortColors(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        int n = nums.size();
        /*unordered_map<int,int> freq;
        for(auto & x : nums) freq[x]++;
        for(int i =0;i<freq[0];i++) nums[i] = 0;
        for(int i =freq[0];i<freq[0] + freq[1];i++) nums[i] = 1;
        for(int i =freq[0]+ freq[1];i<n;i++) nums[i] = 2;*/
        int l = 0, mid = 0, r = n-1;
        while(l<=mid && mid <=r){
            if(nums[mid]==0) {
                swap(nums[mid++],nums[l++]);
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[r--]);
            }
            else mid++;
        }
    }
};