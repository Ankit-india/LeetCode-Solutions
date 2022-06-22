class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int sz = nums.size();
        if (sz - 3 < 0){
            return nums[sz - 1];
        }
        return nums[sz - 3];
    }
};