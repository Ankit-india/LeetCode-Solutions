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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0){
            return {};
        }
        
        unordered_map<int,vector<TreeNode*>> mp;
        
        mp[1] = {new TreeNode(0)};
        
        for(int i = 3; i <= n; i += 2){
            int sum = i - 1;
            int leftsum = 1, rightsum = sum - 1;
            while(leftsum <= sum){
                for(auto leftnode: mp[leftsum]){
                    for(auto rightnode: mp[rightsum]){
                        TreeNode* rootnode = new TreeNode(0);
                        rootnode -> left = leftnode;
                        rootnode -> right = rightnode;
                        mp[i].push_back(rootnode);
                    }
                }
                
                leftsum += 2;
                rightsum -= 2;
            }
        }
        
        return mp[n];
    }
};