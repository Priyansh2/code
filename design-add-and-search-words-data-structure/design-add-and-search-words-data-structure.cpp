class node{
  public:
    vector<node *> kids;
    bool isword;
    node(){
        kids = vector<node *> (26);
        isword = false;
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    node * root;
    WordDictionary() {
        root = new node();
    }
    
    void addWord(string word) {
        auto t = root;
        for(auto x : word){
            if(!t->kids[x-'a']) t->kids[x-'a'] = new node();
            t = t->kids[x-'a'];
        }
        t->isword = true;
    }
    bool search_util(string word, int idx, node * t){
        if(idx==word.length()) return t && t->isword;
        if(word[idx]!='.'){
            int j = word[idx]-'a';
            return t->kids[j] && search_util(word,idx+1,t->kids[j]);
        }
        for(int j =0;j<26;j++)
            if(t->kids[j] && search_util(word,idx+1,t->kids[j])) return true;
        return false;
    }
    bool search(string word) {
        return search_util(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */