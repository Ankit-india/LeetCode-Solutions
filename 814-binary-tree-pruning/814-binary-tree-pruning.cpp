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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        if(root -> left == NULL && root -> right == NULL){
            if(root -> val == 1) return root;
            else return NULL;
        }
        TreeNode* lt = pruneTree(root-> left);
        if(lt == NULL) root -> left = NULL;
        TreeNode* rt = pruneTree(root -> right);
        if(rt == NULL) root->right = NULL;
        if(root -> val == 0 && (root -> left == NULL && root-> right == NULL)){
            return NULL;
        }
        return root;
    }
};