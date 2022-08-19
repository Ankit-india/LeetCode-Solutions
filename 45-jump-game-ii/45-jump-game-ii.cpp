class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        
        int reach = nums[0];
        int ans = 1;
        int upto = nums[0];
        
        for(int i = 0; i < nums.size(); i++){
            if(i > upto){
                ans++;
                upto = reach;
            }
            reach = max(reach, i + nums[i]);
        }
        return ans;
    }
};