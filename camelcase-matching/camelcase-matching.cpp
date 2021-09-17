class Solution {
public:
    bool solve(string & word, string & pat){
        int i =0;
        for(int j = 0;j<word.length();j++){
            if(i < pat.length() && pat[i]==word[j]) i++;
            else if(!islower(word[j])) return false;
        }
        return i==pat.length();
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(auto word : queries){
            auto res = solve(word,pattern);
            ans.push_back(res);
        }
        return ans;
    }
};