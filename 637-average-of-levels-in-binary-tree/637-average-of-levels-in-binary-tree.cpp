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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            double res = 0.00000;
            for(int i = 0; i < n; i++){
                TreeNode* t = q.front();
                q.pop();
                if(t-> left != NULL) {
                    q.push(t-> left);
                }
                if(t-> right != NULL) {
                    q.push(t-> right);
                }
                res += t -> val;
            }
            ans.push_back(res/n*1.000);
            
        }
        return ans;
    }
};