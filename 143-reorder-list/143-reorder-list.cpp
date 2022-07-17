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
    void reorderList(ListNode* head) {
        if(!head ) return;
        if(head -> next == NULL) return;
        if(head -> next -> next == NULL) return;
        vector<ListNode*>arr;
        
        ListNode* temp = head;
        
        while(temp != NULL){
            arr.push_back(temp);
            temp = temp -> next;
        }
        
        int i = 0, j = arr.size() - 1;
        while(i <= j){
            arr[i] -> next = arr[j];
            arr[j] -> next = arr[i+1];
            temp = arr[j];
            i++;
            j--;
        }
        if(j - i )
        temp -> next = NULL;
    }
};