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
     int dfs(TreeNode* root, int tempMax){
        if(!root) return 0;
        if(tempMax <= root -> val){
            return 1 + dfs(root -> left,root -> val) + dfs(root -> right,root -> val);
        }
        return dfs(root -> left,tempMax) + dfs(root -> right,tempMax);
    }
    int goodNodes(TreeNode* root) {
        int tempMax = root -> val;
        return dfs(root,tempMax);
    }
};