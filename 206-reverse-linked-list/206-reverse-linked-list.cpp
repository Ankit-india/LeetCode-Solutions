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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(head != NULL && head -> next != NULL){
            temp = head -> next;
            head -> next = prev;
            
            prev = head;
            head = temp;            
        }
        if(head != NULL){
            head -> next = prev;
        }
        return head;
    }
};