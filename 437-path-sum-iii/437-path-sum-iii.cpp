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
     void recursion(TreeNode* root,int targetSum,long long int sum,int& count,unordered_map<int,int>& mp)
    {
        if(!root) return;
        sum+=root->val;
        if(sum == targetSum)
        {
            count++;
        }
        // int req = ;
        if(mp.find(sum-targetSum)!=mp.end())
        {
            count+=mp[sum-targetSum];
        }
        mp[sum]++;
        // if(root -> left != NULL){
            recursion(root->left,targetSum,sum,count,mp);
        // }
        // if(root -> right != NULL){
            recursion(root->right,targetSum,sum,count,mp);
        // }
        mp[sum]--;
        return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int sum = 0,count = 0;
        unordered_map<int,int> mp;
        recursion(root,targetSum,sum,count,mp);
        return count;
    }
};