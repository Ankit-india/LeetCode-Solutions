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
    int sum = 0;
    
    void recur(TreeNode* root, int num){
        if(!root){
            return;
        }
        
        num *= 10;
        num += root -> val;
        
        if(!(root -> left) && !(root -> right)){
            sum += num;
            return;
        }
        recur(root -> left, num);
        recur(root -> right, num);
        
    }
    int sumNumbers(TreeNode* root) {
        if(!root){
            return 0;
        }
        
        recur(root,0);
        return sum;
        
    }
};