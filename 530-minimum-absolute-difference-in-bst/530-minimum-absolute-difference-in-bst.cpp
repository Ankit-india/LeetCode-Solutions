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
            return ;
        }
        
        inorder(root -> left, arr);
        arr.push_back(root -> val);
        inorder(root -> right, arr);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> vec;
        
        inorder(root, vec);
        
        int diff = INT_MAX;
        for(int i = 1; i < vec.size(); i++){
            diff = min(diff, abs(vec[i-1] - vec[i]));
        }
        return diff;
    }
};