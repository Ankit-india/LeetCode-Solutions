/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void lOrderTrav(Node* root, vector<vector<Node*>>& res){
        if(root == NULL) return ;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<Node*>a;
            for(int i = 0; i < n; i++){
                Node* temp = q.front();
                q.pop();
                if(temp -> left != NULL){
                    q.push(temp -> left);
                }
                if(temp -> right != NULL){
                    q.push(temp -> right);
                }
                a.push_back(temp);
            }
            // a.push_back(new Node());
            res.push_back(a);
        }
        // return ans;
    }
    Node* connect(Node* root) {
        if(!root){
            return root;
        }
        vector<vector<Node*>>levelOrder;
        lOrderTrav(root, levelOrder);
        for(int i  = 0; i < levelOrder.size(); i++){
            for(int j = 0; j < levelOrder[i].size() - 1; j++){
                // if(levelOrder[i][j] -> val == INT_MAX){
                //     levelOrder[i][j] -> val = NULL;
                // }
                // else{
                    levelOrder[i][j] -> next = levelOrder[i][j+1];
                // }
            }
            // cout << endl;
        }
        return root;
    }
};