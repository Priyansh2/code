/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node *level_order(Node *root){
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int l =q.size();
            auto dummy = new Node(INT_MAX);
            Node * prev = dummy;
            while(l--){
                auto p =q.front();
                q.pop();
                prev->next = p;
                prev = p;
                if(p->left){
                    q.push(p->left);
                }
                if(p->right){
                    q.push(p->right);
                }
            }
            delete(dummy);
        }
        return root;
    }
    Node* connect(Node* root) {
        return level_order(root);
    }
};