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
class BSTIterator  {
public:
    
    void stackfill(TreeNode* root){
        if(root == NULL){
            return;
        }
        while(root != NULL){
            st.push(root);
            root = root -> left;
        }
    }
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        // TreeNode* temp = root;
        // while(temp != NULL){
        //         st.push(temp);
        //         temp = temp-> left;
        // }
        stackfill(root);
    }
    
    int next() {
        TreeNode* tempNode = st.top();
        st.pop();
        // TreeNode* temp = tempNode;
        // if(temp -> right != NULL){
        //     temp = temp -> right;
        //     while(temp != NULL){
        //         st.push(temp);
        //         temp = temp-> left;
        //     }
        // }
        stackfill(tempNode -> right);
        return (tempNode -> val);
            
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */