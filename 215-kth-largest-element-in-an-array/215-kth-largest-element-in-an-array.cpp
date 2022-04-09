class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Max heap ke top pe max element rhta h
        
        priority_queue<int, vector<int>,greater<int>> maxH;
        
        for(auto x: nums){
            maxH.push(x);
            
        }
        while(maxH.size() > k){
            // if(maxH.size() > k){
            //     maxH.pop();
            // }
            maxH.pop();
        }
        return maxH.top();
    }
};