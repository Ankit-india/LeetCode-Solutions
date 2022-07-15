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
    TreeNode* hSortedArrayToBST (vector<int> nums, int start, int end){
        if(start > end){
            return NULL;
        }
        int mid = start + (end - start) / 2; // Always do this to avoid integer flow
        TreeNode* newNode = new TreeNode(nums.at(mid));
        // Left Sorted array calling
        newNode -> left = hSortedArrayToBST(nums, start, mid-1);
        // Right Sorted array calling 
        newNode -> right = hSortedArrayToBST(nums, mid+1, end);
        return newNode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return hSortedArrayToBST(nums, 0, nums.size()-1);       
    }
};