/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    
    void solve(TreeNode* og, TreeNode* copy, TreeNode* target, TreeNode*& ans) {
        if(!og) return;
        
        if(og == target) {
            ans = copy;
        }
        
        solve(og->left, copy->left, target, ans);
        solve(og->right, copy->right, target, ans);
        
        return;
    }
    
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        TreeNode* ans = nullptr;
        solve(original, cloned, target, ans);
        return ans;
    }
};