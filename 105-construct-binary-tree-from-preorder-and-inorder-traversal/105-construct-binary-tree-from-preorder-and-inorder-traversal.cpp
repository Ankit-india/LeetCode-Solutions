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
    TreeNode* newBuildTree(vector<int> preorder, int psi, int pei, vector<int> inorder, int isi, int iei){
        if(isi > iei) return NULL;
        
        int idx = isi;
        while(inorder[idx] != preorder[psi]){
            idx++;
        }
        int count = idx - isi;
        TreeNode* node = new TreeNode(preorder[psi]);
        
        node->left =newBuildTree(preorder, psi + 1, psi+count, inorder, isi,idx - 1);
        node->right = newBuildTree(preorder, psi + count + 1, pei, inorder, idx + 1, iei);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return newBuildTree(preorder, 0, preorder.size() - 1, inorder, 0, preorder.size()-1);
    }
};