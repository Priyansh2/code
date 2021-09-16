class node{
  public:
    unordered_map<char,node*> kids;
    bool isprefix;
    node(){
        kids.clear();
        isprefix = false;
    }
};
class Solution {
public:
    void insert(string & s, node * root){
        for(auto x : s){
            if(root->kids.count(x)==0) root->kids[x] = new node();
            root = root->kids[x];
        }
        root->isprefix = true;
    }
    string get_root(node *root, string &word){
        string ans;
        for(int i =0;i<word.length(), !root->isprefix;i++){
            if(root->kids.count(word[i])==0) return "";
            ans.push_back(word[i]);
            root =root->kids[word[i]];
        }
        return ans;
    }
    string replaceWords(vector<string>& dictionary, string &sentence) {
        node * root = new node();
        for(auto s : dictionary){
            insert(s,root);
        }
        stringstream in(sentence);
        string word;
        string res;
        while ( in >> word){
            auto p = get_root(root,word);
            if(p.length()) res.append(p);
            else res.append(word);
            res.append(" ");
        }
        res.pop_back();
        return res;
    }
};