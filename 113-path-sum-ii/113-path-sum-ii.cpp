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
    void solve(TreeNode* root, vector<vector<int>>& res, vector<int> arr, int temp, int tSum){
        if(!root){
            return;
        }
        
        if(root -> left == NULL && root -> right == NULL){
            if(temp + root -> val == tSum){
                arr.push_back(root -> val);
                res.push_back(arr);
            }
        }
        temp += root -> val;
        arr.push_back(root -> val);
        solve(root -> left, res, arr, temp, tSum);
        solve(root -> right, res, arr, temp, tSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        int sum = 0;
        solve(root, ans, v, sum, targetSum);
        return ans;
    }
};