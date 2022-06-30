class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        // int temp = nums[n / 2];
        for(int i = 1; i < n; i++){
            ans += abs(nums[0] - nums[i]);
        }
        // if(ans != 0)return ans+1;
        return ans;
    }
};