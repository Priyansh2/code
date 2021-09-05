/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
    TreeNode *myroot;
    deque < TreeNode*> dq;
    void init(TreeNode * root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            if(p->left){
                q.push(p->left);
            }
            if(p->right){
                q.push(p->right);
            }
            if(!p->left || !p->right) dq.push_back(p);
        }
    }
public:
    
    CBTInserter(TreeNode* root) {
        myroot = root;
        init(myroot);
    }
    
    int insert(int val) {
        auto t = new TreeNode(val);
        auto node = dq.front();
        if(!node->left) node->left  = t;
        else if(!node->right){
            node->right = t;
            dq.pop_front();  
        }
        dq.push_back(t);
        return node->val;
        
    }
    
    TreeNode* get_root() {
        return myroot;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */