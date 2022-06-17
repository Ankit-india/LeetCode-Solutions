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
    // int ans = 0;
    int minCamera(TreeNode* root, int& ans) {
        if(root == NULL){
            return 1;
            
        }
        int lc = minCamera(root -> left, ans);
        int rc = minCamera(root -> right, ans);
        
        if(lc == -1 || rc == -1){
            ans++;
            return 0;
        }
        if(lc == 0 || rc == 0){
            // ans++;
            return 1;
        }
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        int camera = 0;
        int ans = minCamera(root, camera);
        if(ans == -1){
            camera++;
        }
        return camera;
    }
};