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
    int numComponents(ListNode* head, vector<int>& nums) {
//         int ans = 0, sum = 0, i = 0;
//         ListNode *temp = head;
//         while(temp != NULL){
//             if(temp -> val == nums[i]){
//                 sum++;
                
//                 // cout << temp -> val << " -> "<< nums[i] << ", ";
//                 i++;
//             }
//             else{
//                 // cout <<nums[i] <<  endl;
//                 sum = 0;
//                 if(i != 0){
//                     ans++;
//                 }
//             }
//             temp = temp -> next;
//         }
//         if(sum != 0){
//             ans++;
//         }
//         return ans;
        unordered_set<int>mp(nums.begin(),nums.end());
        int ans = 0;
        bool prev = 0;
        while(head){
            if( mp.find(head->val) == mp.end() ){
                prev=0;
            }else{
                if(!prev ) {
                    ans++;
                    prev=1;
                }
            }
            head=head->next;
        }
        return ans;
    }
};