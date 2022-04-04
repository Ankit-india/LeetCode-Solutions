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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int ct = 0;
        while(temp != NULL){
            ct++;
            temp = temp -> next;
        }
        // NUmber of Node is stored in ct
        int left = k;
        int right = ct - k + 1;
        cout <<"ct = " << ct << endl<< left << endl << right << endl;
        ListNode* n1 = NULL, *n2 = NULL;
        
        temp = head;
        int t = 0;
        
        while(t != left){
            t++;
            n1 = temp;
            temp = temp -> next;
        }
        temp = head;
        t = 0;
        
        while(t != right){
            t++;
            n2 = temp;
            temp = temp -> next;
        }
        temp = NULL;
        
        swap(n1 -> val, n2 -> val);
        return head;
    }
};