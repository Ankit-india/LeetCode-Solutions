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
    void display(ListNode* head){
        if(head == NULL){
            return;
        }
        cout << head -> val;
        display(head -> next);
    }
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head -> next == NULL ){
            return head;
        }
//         ListNode* small = NULL;
//         ListNode* prevSmall = small;
//         ListNode* temp = head;
//         // display(head);
//         while(temp != NULL){
//             if(temp -> val < x){
//                 ListNode* t = new ListNode(temp->val,temp-> next);
                
            
//                 if(small == NULL){
//                     small = t;
//                     prevSmall = small;
//                 }
//                 else{
//                     prevSmall -> next = t;
//                     prevSmall = t;
//                 } 
//             }
//             temp = temp -> next;
//         }    
//         // display(small);
//         // cout<< prev -> next ->val;
//         // ListNode* a = small;
//         // while(a->next!= NULL){
//         //     a = a-> next;
//         // }
//         // prev = a;
//         temp = head;
//         // cout << temp -> val;
//         ListNode* large = NULL;
//         ListNode* prev = large;
//         // display(head);
//         while(temp != NULL){
//             if(temp -> val >= x){
//                 ListNode* t = new ListNode(temp ->val, temp -> next);
//                 if(large == NULL){
//                     large = t;
//                     prev = large;
//                 }
//                 else{
//                     prev -> next = t;
//                     prev = t;
//                 } 
//             }
//             temp = temp -> next;
//         }
//         // cout << prev -> val;
//         // cout << temp -> val;
//         // if(temp == NULL && prev -> val < x){
//         //     cout << "ankit ";
//             prev -> next = NULL;
//         // }
//         // display(large);
//         prevSmall->next = large;
//         return small;
        ListNode* s = new ListNode(0);
        ListNode* h = new ListNode(0);
        ListNode* sHead = s, *hHead = h;
        while(head != NULL){
            if(head -> val < x){
                sHead -> next = head;
                sHead = sHead -> next;
            }
            else{
                hHead -> next = head;
                hHead = hHead -> next;
            }
            head = head -> next;
        }
        hHead -> next = NULL;
        sHead -> next = h -> next;
        return s -> next;
    }
};