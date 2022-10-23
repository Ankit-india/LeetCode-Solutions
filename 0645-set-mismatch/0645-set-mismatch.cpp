class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate = -1;
        int missing = -1;
        
        for(int i = 0; i<nums.size(); i++) {
            int idx = abs(nums[i]);
            
            if(nums[idx-1] < 0) duplicate = idx;
            else nums[idx-1] *= (-1);
        }
        
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] > 0) {
                missing = i+1;
                break;
            }
        }
        
        return {duplicate, missing};
    }
};