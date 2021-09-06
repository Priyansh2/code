/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    //we use here perorder traversal alone and since it traversed the tree in following order : root, left, right -> which is also the direction of level order traversal and hence, we use queue data structure to later decode/deserialize our coded string. 
    string serialize(TreeNode* root) {
       if(!root) return "N,";
       return serialize(root->left)+serialize(root->right)+to_string(root->val)+",";
    }

    // Decodes your encoded data to tree.
    TreeNode* solve(stack<string>&q){
        auto s =q.top();
        q.pop();
        if(s=="N") return NULL;
        TreeNode* root=new TreeNode(stoi(s));
        root->right=solve(q);
        root->left=solve(q);
        
        return root;
    }
    TreeNode* deserialize(string data) {
        cout <<data<<endl;
        stack<string> q;
        string s;
        for(int i=0;i<data.size();i++){
            if(data[i]==','){
                cout <<s<<endl;
                q.push(s);
                s="";
                continue;
            }
            s.push_back(data[i]);
        }
        /*if(s.size()!=0){
            cout <<"ok!"<<endl;
            cout <<s<<endl;
            q.push(s);
        }*/
        return solve(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));