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
    
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        unordered_map<ListNode*, ListNode*> mp;
        
        while(temp != NULL){
            if(mp.find(temp) != mp.end()){
                return temp;
            }
            else{
                mp[temp] = temp;
                temp = temp -> next;
            }
        }
        return NULL;
    }
};