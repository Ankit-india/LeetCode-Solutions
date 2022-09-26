class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum_so_far = INT_MIN;
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            max_sum_so_far = max(sum, max_sum_so_far);
            if(sum < 0){
                sum = 0;
            }
        }
        return max_sum_so_far;
    }
};