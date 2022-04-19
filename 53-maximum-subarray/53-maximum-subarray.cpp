class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int temp1=nums[0],temp2=nums[0];
        for(int i=1;i<nums.size();i++){
            temp1=max(temp1+nums[i],nums[i]);
            temp2=max(temp2,temp1);
        }
        return temp2;
    }
};