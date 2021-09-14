class node{
  public:
    vector<node*> kids;
    string str;
    node(){
        kids = vector<node*> (26);
        str = "#";
    }
    
};
class Solution {
public:
    void insert(node * root, string &s){
        auto t =root;
        for(auto x : s){
            int j = x-'a';
            if(!t->kids[j]) t->kids[j] = new node();
            t  = t->kids[j];
            
        }
        t->str = s;
    }
    vector<string> res;
    bool nokids(node * root){
        for(int i =0;i<26;i++){
            if(root->kids[i]) return false;
        }
        return true;
    }
    void dfs(int i, int j, vector<vector<char>> &board, node * root, node *parent){
        int m = board.size(), n = board[0].size();
        if(!root) return;
        auto c  =board[i][j];
        if(root->str!="#"){
            //cout << i << " "<< j << "ok!"<<endl;
            res.push_back(root->str);
            root->str = "#";
        }
        board[i][j] = '#';
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        for(auto d : dir){
            int x = d.first + i, y = d.second + j;
            if(x>=m || y>=n || x<0 || y<0 || board[x][y]=='#') continue; 
            
            dfs(x,y,board,root->kids[board[x][y]-'a'],root);
        }
        board[i][j] = c;
        if(nokids(root)){
            //cout << "sasa:" << i <<" "<< j <<" "<< board[i][j] <<endl; 
            delete (root);
            parent->kids[c-'a'] = nullptr;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        res.clear();
        int m = board.size(), n = board[0].size();
        node * root = new node();
        for(auto s : words){
            insert(root, s);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                auto c = board[i][j];
                if(root->kids[c-'a']) dfs(i,j,board, root->kids[c-'a'] , root);
            }
        }
        return res;
    }
};