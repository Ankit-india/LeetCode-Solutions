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
    vector<int> inorder(vector<int>& res, TreeNode* root){
        if(root == NULL) return res;
        
        inorder(res, root -> left);
        res.push_back(root -> val);
        inorder(res, root -> right);
        
        return res;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> getRes;
        getRes = inorder(getRes, root);
        bool flag = true;
        for(int i = 1; i < getRes.size(); i++){
            if(getRes.at(i-1) >= getRes.at(i)){
                flag = false;
            }
        }
        return flag;
    }
};