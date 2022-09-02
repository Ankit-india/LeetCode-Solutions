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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        TreeNode* ans;
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, int> p, c;
        
        for(vector<int> x: des){
            if(mp.find(x[0]) == mp.end()){
                TreeNode* temp = new TreeNode(x[0]);
                mp[x[0]] = temp;
            }
            if(mp.find(x[1]) == mp.end()){
                TreeNode* temp = new TreeNode(x[1]);
                mp[x[1]] = temp;
            }
            if(x[2]){
                mp[x[0]] -> left = mp[x[1]];
            }
            else{
                mp[x[0]] -> right = mp[x[1]];
            }
            p[x[0]]++;
            c[x[1]]++;
        }
        for(auto x: mp){
            if(p.find(x.first) != p.end() && c.find(x.first) == c.end()){
                ans=x.second;
            }
        }
        return ans;
    }
};