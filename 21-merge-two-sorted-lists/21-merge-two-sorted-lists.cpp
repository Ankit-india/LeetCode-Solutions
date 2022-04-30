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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        while(list1 != NULL && list2 != NULL){
            if(list1 -> val <= list2 -> val){
                temp -> next = list1;
                temp = list1;
                list1 = list1 -> next;
            }
            else{
                temp -> next = list2;
                temp = temp -> next;
                list2 = list2 -> next;
            }
        }
        // cout << temp -> val;
        while(list1 != NULL){
            temp -> next = list1;
            temp = temp -> next;
            list1 = list1 -> next;
        }
        while(list2 != NULL){
            temp -> next = list2;
            temp = temp -> next;
            list2 = list2 -> next;
        }
        
        
        
        
        return head -> next;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // ListNode* ptr1 = list1;
        // ListNode* ptr2 = list2;
        // ListNode* head = NULL;
        // while(ptr1 != NULL && ptr2 != NULL){
        //     if(ptr1 != NULL && ptr2 != NULL && ptr1 -> val <= ptr2 -> val){
        //         if(head == NULL){
        //             head = ptr1;
        //         }
        //         ListNode* prev = ptr1 -> next;
        //         ptr1 -> next = ptr2;
        //         ptr1 = prev; 
        //     }
        //     if(ptr1 != NULL && ptr2 != NULL && ptr1 -> val > ptr2 -> val){
        //         if(head == NULL){
        //             head = ptr2;
        //         }
        //         ListNode* prev = ptr2 -> next;
        //         ptr2 -> next = ptr1;
        //         ptr2 = prev;
        //     }
        // }
        // return head;
    }
};