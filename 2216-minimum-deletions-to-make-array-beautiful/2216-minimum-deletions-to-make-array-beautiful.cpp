class Solution {
public:
    int minDeletion(vector<int>& nums) {
        bool eq = 0;
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(i % 2 == eq && i + 1 < n && nums[i] == nums[i+1]){
                ans++, eq=!eq;
            }
        }
        return ans+(n-ans)%2;
    }
};