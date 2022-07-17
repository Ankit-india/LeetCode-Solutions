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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head)  return head;
        if(head -> next == NULL) return NULL;
        // if(head -> next -> next == NULL) head -> next = NULL;cout << ":"; return head;
        vector<ListNode*> arr;
        
        ListNode* temp = head;
        
        while(temp != NULL){
            arr.push_back(temp);
            temp = temp -> next;
        }
        if(arr.size() == 2){
            arr[0] -> next = NULL;
            return head;
        }
        int mid = floor(arr.size() / (2 * 1.0));
        // cout << mid << endl;
        arr[mid-1] -> next = arr[mid+1];
        return head;
//         ListNode* fast = head, *slow = head, *prev = slow;
        
//         while(fast != NULL){
//             if(fast -> next -> next != NULL){
//                 fast = fast -> next -> next;
//             }
//             else break;
//             prev = slow;
//             slow = slow -> next;
//         }
        
//         prev -> next = slow -> next;
//         return head;
    }
};