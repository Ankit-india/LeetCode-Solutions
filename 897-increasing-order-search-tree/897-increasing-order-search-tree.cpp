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
    void inorder(TreeNode* root, vector<int>& arr){
        if(!root){
            return;
        }
        inorder(root -> left, arr);
        arr.push_back(root -> val);
        inorder(root -> right, arr);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root -> left && !root -> right){
            return root;
        }
        vector<int> a;
        inorder(root,a);
        TreeNode* prev = NULL;
        bool flag = true;
        for(auto x: a){
            TreeNode* temp = new TreeNode(x);
            if(flag){
                // root -> left = NULL;
                // root -> right = temp;
                root = temp;
                // cout << temp -> val;
                prev = root;
                flag = false;
            }
            prev -> right = temp;
            prev = temp;
            
            // cout << x << endl;
        }
        
        return root;
        
    }
};