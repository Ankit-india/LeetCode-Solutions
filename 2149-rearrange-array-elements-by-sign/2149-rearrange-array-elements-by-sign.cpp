class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> neg, pos;
        
        for(auto x: nums){
            if(x < 0){
                neg.push(x);
            }
            else {
                pos.push(x);
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(i & 1){
                nums[i] = neg.front();
                neg.pop();
            }
            else {
                nums[i] = pos.front();
                pos.pop();
            }
        }
        return nums;
    }
};