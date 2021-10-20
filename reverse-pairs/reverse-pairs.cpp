class Solution {
public:
    int get_count(vector<int> &bit, int i){
        int cnt=0;
        for(int j=i;j>0;j = j - (j &(-j)))
            cnt+=bit[j];
        return cnt;
    }
    void update(vector<int> &bit, int i, int val){
        for(int j=i;j<bit.size();j = j + (j & (-j)))
            bit[j]+=val;
    }
    int solve1(vector<int>&nums){
        int res=0;
        int n = nums.size();
        unordered_map<long,int> index;
        vector<long > temp;
        for(int i =0;i<n;i++){
            //long t = nums[i];
            //t=t*2;
            temp.push_back(nums[i]);
            temp.push_back(2L*nums[i]);  
        } 
        set<long> st(temp.begin(),temp.end());
        int c=1;
        for(auto it=st.begin();it!=st.end();it++){
            //cout <<*it<<" "<<c<<endl;
            index[*it]=c++;
            
        }
        vector<int> bit(index.size()+1,0);
        for(int i =n-1;i>=0;i--){
            res+= get_count(bit,index[nums[i]]-1);
            update(bit,index[2L*nums[i]],1);
        }
        return res;
    }
    int merge(vector<int>&nums, int l, int r){
        vector<int> temp(r -l +1);
        int mid = (l +r )/2;
        int i =l, j = mid +1, k =0, cnt = 0;
        while(i<=mid && j<=r){
            if(nums[i] > (long long) 2 * nums[j]) {
                cnt+=mid+1 - i;
                j++;
            }
            else i++;
        }
        i = l;
        j = mid +1;
        while(i<=mid && j<=r){
            if(nums[i]<=nums[j]) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        }
        while(i<=mid) temp[k++] = nums[i++];
        while(j<=r) temp[k++] = nums[j++];
        for(int i = l;i<=r;i++) nums[i] = temp[i-l];
        return cnt;
    }
    int mergesort(vector<int>&nums, int l, int r){
        if(l>=r) return 0;
        int mid = (l +r )/2;
        int cnt = mergesort(nums, l, mid);
        cnt+=mergesort(nums, mid +1, r);
        return cnt + merge(nums, l, r);
    }
    int solve2(vector<int>&nums){
        return mergesort(nums,0,nums.size()-1);
    }
    int reversePairs(vector<int>& nums) {
        //return solve1(nums);
        return solve2(nums);
    }
};