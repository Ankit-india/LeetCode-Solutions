class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums.at(0);
        if(nums.size() == 2) return max(nums.at(0), nums.at(1));
        int res = 0;
        for(int i = 2; i < nums.size(); i++){
            int ans = max(nums.at(i-1), nums.at(i-2));
            nums[i-1] = ans;
            nums[i] = nums[i] + nums[i-2];
            nums[i] = max(nums.at(i), nums.at(i-1));
            res = nums[i];
        }
        return res;
    }
};