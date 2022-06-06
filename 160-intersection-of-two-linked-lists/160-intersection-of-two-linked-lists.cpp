/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // implement doThis here
    ListNode* doThis(ListNode* h, int diff){
        while(diff--){
            h = h -> next;
        }
        return h;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL){
            return headB;
        }
        if(headB == NULL){
            return headA;
        }
        ListNode* tempA = headA;
        int a = 0;
        while(tempA != NULL){
            a++;
            tempA = tempA->next;
        }
        ListNode* tempB = headB;
        int b = 0;
        while(tempB != NULL){
            b++;
            tempB = tempB->next;
        }
        if(a > b){
            headA = doThis(headA, a-b);
        }
        else{
            headB = doThis(headB, b-a);
        }
        while(headA != headB){
            headA = headA -> next;
            headB = headB -> next;
        }
        return headA;
    }
};