class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<pair<int,int>,int> freq;
        unordered_map<int,int> mp;
        for(int i =0;i<arr2.size();i++) mp[arr2[i]] = i;
        vector<int> res;
        for(auto & x : arr1){
            if(mp.count(x)==0) res.push_back(x);
            else freq[{mp[x],x}]++;
        }
        vector<int> temp;
        for(auto &it :freq){
            int val = it.first.second;
            while(it.second--)
                temp.push_back(val);
        }
        sort(res.begin(),res.end());
        temp.insert(temp.end(),res.begin(),res.end());
        return temp;
        
    }
};