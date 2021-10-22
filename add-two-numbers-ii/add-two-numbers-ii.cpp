/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#define node ListNode

class Solution {
public:
    void rev_list(node ** l1, int &len){
        node * curr = *l1, *prev = nullptr, *curr_next = nullptr;
        while(curr){
            len++;
            curr_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = curr_next;
        }
        *l1 = prev;
    }
    node * solve1(node* l1, node *l2){
        int len1=0, len2=0;
        rev_list(&l1,len1);
        rev_list(&l2,len2);
        if(len1  > len2) {
            swap(len1,len2);
            swap(l1,l2);
        }
        auto temp = l2;
        int carry = 0;
        node*  t = nullptr;
        for(;l1; l1 = l1->next, t = l2, l2=l2->next){
            int sum = l1->val + l2->val +carry;
            int rem = sum%10;
            carry = sum/10;
            //t = l2;
            l2->val = rem;
        }
        for(;l2;t=l2,l2=l2->next){
            int sum = l2->val + carry;
            int rem = sum%10;
            carry = sum/10;
            l2->val = rem;
            //t = l2;
        }
        if(carry!=0){
            t->next = new node(carry);
        }
        int len = 0;
        rev_list(&temp,len);
        return temp;
    }    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return solve1(l1,l2);
    }
};