 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "";
        }
        string ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = NULL;
            int len = q.size();
            for(int i = 0; i < len; i++){
                node = q.front();
                q.pop();
                if(node != NULL){
                    if(ans==""){
                        ans+=(std::to_string(node->val));
                    }else{
                        ans+=(","+std::to_string(node->val));
                    }
                    q.push(node->left);
                    q.push(node->right);
                }else{
                    if(ans==""){
                        ans+=("null");
                    }else{
                        ans+=",null";
                    }
                }
            }
        }
        
        
        return ans;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return NULL;
        }
        stringstream str_s(data);
        string str;
        getline(str_s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            getline(str_s, str, ',');
            
            if(str == "null" or str == "null]"){
                curr->left = NULL;
            }else {
                TreeNode* left_node = new TreeNode(stoi(str));
                curr->left = left_node;
                q.push(left_node);
            }
            
            getline(str_s, str, ',');

            if(str == "null" or str == "null]"){
                curr->right = NULL;
            }else{
                cout << str << endl;
                TreeNode* right_node = new TreeNode(stoi(str));
                curr->right = right_node;
                q.push(right_node);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
 
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Codec {
// public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         if(!root) return "";
//         string ans = "";
//         ans += to_string(root -> val);
//             ans += ',';
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
//             TreeNode* temp = q.front();
//             q.pop();
//             if(temp -> left != NULL){
//                 q.push(temp -> left);
//                 ans += to_string(temp ->left -> val);
//                 ans += ',';
//             }
//             else{
//                 ans += "n,";
//             }
//             if(temp -> right != NULL){
//                 q.push(temp -> right);
//                 ans += to_string(temp ->right -> val);
//                 ans += ',';
//             }
//             else {
//                 ans += "n,";
//             }
            
//         }
//         // cout << ans;
//         return ans;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         if(data.size() == 0) return NULL;
//         queue<int>q;
//         for(int i = 0; i < data.size(); i++){
//             string s = "";
//             while(data[i] != ','){
//                 s+=data[i];
//                 i++;
//             }
//             if(s != "n"){
//                 q.push(stoi(s));
//             }
//             else {
//                 q.push(INT_MAX);
//             }
//         }
//         TreeNode* root = new TreeNode(q.front());
//         q.pop();
//         TreeNode* dummy = root;
        
//         while(!q.empty()){
//             int leftTemp = q.front();
//             q.pop();
//             int rightTemp = q.front();
//             q.pop();
//             if(leftTemp == INT_MAX) dummy ->left = NULL; dummy = 
//             if(rightTemp == INT_MAX) dummy -> right = NULL;
//             TreeNode lt = new TreeNode(leftTemp);
//             dummy -> left = lt;
//             TreeNode rt = new TreeNode(rightTemp);
//             dummy -> right = rt;
//             dummy = dummy -> left;
            
//         }
//         return nullptr;
//     }
// };

// // Your Codec object will be instantiated and called as such:
// // Codec ser, deser;
// // TreeNode* ans = deser.deserialize(ser.serialize(root));