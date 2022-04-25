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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>a;
            for(int i = 0; i < n; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp -> left != NULL){
                    q.push(temp -> left);
                }
                if(temp -> right != NULL){
                    q.push(temp -> right);
                }
                a.push_back(temp -> val);
            }
            ans.push_back(a);
        }
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> ans = levelOrder(root);
        vector<int> res;
        for(int i = 0; i < ans.size(); i++){
            res.push_back(ans[i].back());
        }
        return res;
    }
};