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
    ListNode* insertAtEndLL(ListNode* head, int data){
        ListNode* newNode = new ListNode(data);
        if(head == NULL){
            return newNode;
        }
        ListNode* temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        int sum = 0;
        ListNode* head = NULL;
        while(l1 != NULL || l2 != NULL){
            if(l1 != NULL) {
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2 != NULL){
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            if(sum > 9){
                head = insertAtEndLL(head, sum % 10);
            }
            else{
                head = insertAtEndLL(head, sum);
            }
            sum /= 10;
        }
        if(sum != 0){
            head = insertAtEndLL(head, sum);
        }
        return head;
    }
};