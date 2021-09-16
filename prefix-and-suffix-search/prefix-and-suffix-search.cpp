class node{
  public:
    unordered_map<char,node*> kids;
    int id;
    node(){
        id = -1;
    }
};
class WordFilter {
public:
    node * root;
    void insert(node * root, string &s, int k){
        for(auto x : s){
            if(!root->kids[x]) root->kids[x] = new node();
            root =root->kids[x];
            root->id = k;
        }
        
    }
    WordFilter(vector<string>& words) {
        root = new node();
        int j=0;
        for(auto word : words){
            string s;
            for(int i =word.length()-1;i>=0;i--){
                s=word[i]+s;
                auto t = s+"#"+word;
                insert(root,t,j);
            }
            j++;
        }
    }
    int search(node * root, string &s){
        int res;
        for(int i =0;i<s.length() && root;i++){
            root =root->kids[s[i]];
            res = root ? root->id: -1;
        }
        return res;
    }
    int f(string prefix, string suffix) {
        auto t = suffix + "#" + prefix;
        return search(root,t);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */