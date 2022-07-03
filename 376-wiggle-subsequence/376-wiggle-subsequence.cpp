class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int prevSign = nums[1] - nums[0];
        int ans = prevSign != 0 ? 2:1;
        for(int i=2;i<nums.size();i++){
            int currSign = nums[i] - nums[i-1];
            if((currSign > 0 && prevSign <= 0) || (currSign < 0 && prevSign >= 0)){
                ans++;
                prevSign = currSign;
            }
        }
        return ans;
    }
};