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
    void preorder(TreeNode* root, vector<TreeNode*>& res){
        if(!root) return ;
        
        res.push_back(root);
        preorder(root -> left,res);
        preorder(root -> right,res);
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<TreeNode*> arr;
        preorder(root, arr);
        TreeNode* prev = root;
        // prev -> left = NULL;
        for(int i = 0; i < arr.size() - 1; i++){
            prev -> left = NULL;
            prev -> right = arr[i+1];
            prev = arr[i+1];
        }        
    }
};