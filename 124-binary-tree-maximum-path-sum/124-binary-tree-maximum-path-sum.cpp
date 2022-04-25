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
    int dfs(TreeNode* root, int& ans){
        if(!root){
            return 0;
        }
        
        int num1 = dfs(root -> left, ans);
        int num2 = dfs(root -> right, ans);
        
        int l = max(0, num1);
        int r = max(0, num2);
        
        ans = max(ans, l + r + root -> val);
        
        return (root -> val + max(l,r));
       
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root,res);
        return res;
    }
};