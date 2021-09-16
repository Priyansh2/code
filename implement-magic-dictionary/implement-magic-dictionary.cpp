class MagicDictionary {
public:
    /** Initialize your data structure here. */
    unordered_set<string> st;
    MagicDictionary() {
        st.clear();
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto x : dictionary) st.insert(x);
    }
    
    bool search(string searchWord) {
        auto t = searchWord;
        for(int i =0;i<searchWord.length();i++){
            auto c =searchWord[i];
            for(int j = 0;j<26;j++){
                if(c==j+'a') continue;
                searchWord[i] = j + 'a';
                if(st.count(searchWord)) return true;
            }
            searchWord[i] = c;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */