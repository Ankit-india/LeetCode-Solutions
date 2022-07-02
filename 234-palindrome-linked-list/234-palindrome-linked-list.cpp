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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        int ct = 0;
        while(temp != NULL){
            ct++;
            temp = temp -> next;
        }
        stack<ListNode*> st;
        int n = ct / 2;
        int i = 0;
        temp = head;
        while(i < n){
    //         cout << temp ->data  << " ";
            st.push(temp);
            i++;
            temp = temp -> next;
        }
        if(ct&1) temp = temp ->next;
        while(temp != NULL){
            if(st.top() -> val != temp -> val){
                return false;
            }
            st.pop();
            temp=temp->next;
        }
        return true;
    }
};