class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // for(auto x: nums){
        //     cout << x << endl;
        // }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i != nums[i]){
                ans = i;
                break;
            }
        }
        if(nums[nums.size()-1] == nums.size()-1){
            ans = nums.size();
        }
        return ans;
    }
};