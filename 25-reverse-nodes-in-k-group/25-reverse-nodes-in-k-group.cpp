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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return head;
        }
        int s = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp -> next;
            s++;
        }
        temp = head;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* prev = dummyNode;
        while(temp != NULL && s >= k){
            stack<ListNode*> st;
            int i = k;
            while(i > 0 && (s >= k) && temp != NULL){
                st.push(temp);
                temp = temp -> next;
                i--;
            }
            s -= k;
            while(!st.empty()){
                prev -> next = st.top();
                st.pop();
                prev = prev -> next;
                cout << prev-> val << endl;
            }
        }
        prev -> next = temp;
        return dummyNode -> next;
        
        
    }
};