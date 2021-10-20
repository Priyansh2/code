class Solution {
public:
    int local(vector<int>&nums){
        int cnt=0;
        int n = nums.size();
        for(int i =0;i<=n-2;i++){
            if(nums[i] > nums[i+1]) cnt++;
        }
        return cnt;
    }
    int merge(vector<int> &nums, int l, int r){
        vector<int> temp (r -l +1);
        int mid = l + (r -l )/2;
        int i =l, j = mid +1, k =0;
        int cnt =0;
        while(i<=mid && j <=r){
            if(nums[i]<=nums[j]) temp[k++] = nums[i++];
            else {
                cnt+=mid +1 - i;
                temp[k++] = nums[j++];
            }
        }
        while(i<=mid ) temp[k++] = nums[i++];
        while(j<=r) temp[k++] = nums[j++];
         i =l;
        for(;i<=r;i++){
            nums[i] = temp[i-l];
        }
        return cnt;
    }
    int global(vector<int> &nums, int l, int r){
        if(l>=r) return 0;
        int mid = l + (r- l)/2;
        auto cnt = global(nums, l, mid);
        cnt+=global(nums,mid+1,r);
        return cnt + merge(nums,l,r);
    }
    bool solve1(vector<int>&nums){
        int n = nums.size();
        auto a = local(nums);
        auto b = global(nums, 0,n-1);
        //cout <<a << " " << b<< endl;
        return a==b;
    }
    bool solve2(vector<int> &nums){
        int n = nums.size();
        int mine = INT_MAX;
        for(int i =n-3;i>=0;i--){
            mine = min(mine,nums[i+2]);
            if(nums[i] >= mine) return false;
        }
        return true;
    }
    bool solve3(vector<int> &nums){
        int n  = nums.size();
        for(int i =0;i<n-1;i++){
            if(nums[i]  > nums[i+1]){
                swap(nums[i],nums[i+1]);
                i++;
            }
        }
        for(int i =0;i<n-1;i++){
            if(nums[i]  > nums[i+1]) return false;
        }
        return true;
    }
    bool isIdealPermutation(vector<int>& nums) {
        //return solve1(nums);
        //return solve2(nums);
        return solve3(nums);
    }
};