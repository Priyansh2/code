class Solution {
public:
    vector<vector<int>> solve1(vector<int>&nums, int target){
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i =0;i<n-4+1;i++){
            if(i > 0 && nums[i]==nums[i-1]) continue;
            res.push_back({});
            res.back().push_back(nums[i]);
            vector<vector<int>> temp2;
            for(int j = i+1;j<n-4+2;j++){
                if(j > i+1 && nums[j]==nums[j-1]) continue;
                int k = j+1, l = n-1;
                int sum = target - (nums[i]  + nums[j]);
                temp2.push_back({});
                temp2.back().push_back(nums[j]);
                vector<vector<int>> temp;
                while(k < l){
                    int t = nums[k] + nums[l];
                    if(t == sum){
                        //cout << nums[i] << " " << nums[j] << " " << nums[k] << " " <<nums[l] << endl;
                        temp.push_back({nums[k],nums[l]});
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l] == nums[l+1]) l--;
                    }
                    else if(t <sum) k++;
                    else l--;
                }
                vector<int> t = temp2.back();
                vector<vector<int>> t2;
                for(auto &p: temp){
                    t.insert(t.end(),p.begin(),p.end());
                     t2.push_back(t);
                    t = temp2.back();
                }
                temp2.pop_back();
                for(auto &p: t2) temp2.push_back(p);
            }
            vector<int> t = res.back();
            vector<vector<int>> t2;
            for(auto &p: temp2){
                t.insert(t.end(),p.begin(),p.end());
                 t2.push_back(t);
                t = res.back();
            }
            res.pop_back();
            for(auto &p: t2) res.push_back(p);
            
        }
        return res;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        return solve1(nums,target);
    }
};