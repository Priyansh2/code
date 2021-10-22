class Solution {
public:
    string reorganizeString(string &s) {
        unordered_map <char,int> mp;
        for(auto &x : s) mp[x]++;
        multimap<int,char,greater<int>> mp2;
        for(auto &it : mp){
            int freq = it.second;
            char ch = it.first;
            mp2.insert({freq,ch});
        }
        if(mp2.begin()->first > (s.length()+1)/2) return "";
        string res(s.length(),'0');
        int i =0;
        for(auto it = mp2.begin();it!=mp2.end();it++){
            int p = it->first;
            while(p--){
                if(i>=s.length()) i = 1;
                res[i] = it->second;
                i+=2;
            }
        }
        return res;
    }
};