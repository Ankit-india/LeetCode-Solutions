/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int rowMin = 0;
        int rowMax = m-1;
        
        // cout << matrix[0].size();
        vector<vector<int>> ans(m, vector<int>(n,-1));
        int colMin = 0;
        int colMax = n-1;
        int count  = 0;
        while(count < m * n){
            // up
            // vector<int> temp;
            for(int i = colMin;  i <= colMax && count < m * n ; i++){
                // temp.push_back(head -> val);
                ans[rowMin][i] = head -> val;
                head = head -> next;
                if(head == NULL){
                    return ans;
                }
                count++;

            }
            // ans.push_back(temp);
            // temp.clear();
            rowMin++;
            //right
            for(int i = rowMin; i <= rowMax && count < m * n ; i++){
                ans[i][colMax] = head -> val;
                head = head -> next;
                if(head == NULL){
                    return ans;
                }
                count++;

            }
            colMax--;
            //bottom
            for(int i = colMax; i >= colMin && count < m * n ; i--){
                ans[rowMax][i] = head -> val;
                head = head -> next;
                if(head == NULL){
                    return ans;
                }
                count++;

            }
            rowMax--;
            //left
            for(int i = rowMax; i >= rowMin && count < m * n ; i--){
                ans[i][colMin] = head -> val;
                head = head -> next;
                if(head == NULL){
                    return ans;
                }
                count++;
            }
            colMin++;
            if(head == NULL){
                return ans;
            }
        }
        // for(int i = 0; i < n; i++)
        return ans;
    }
};