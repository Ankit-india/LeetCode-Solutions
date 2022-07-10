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
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head,root);
    }
    bool dfs(ListNode* head, TreeNode* root){
        if(!root) return false;
        if(dfshelperfun(head, root)) return true;
        
        return dfs(head, root -> left) || dfs(head, root-> right);
    }
    bool dfshelperfun(ListNode* head, TreeNode* root){
        if(head == nullptr) return true;
        if(root == nullptr || head -> val != root -> val) return false;
        
        return dfshelperfun(head -> next, root -> left) || dfshelperfun(head -> next, root -> right);
        
    }
};