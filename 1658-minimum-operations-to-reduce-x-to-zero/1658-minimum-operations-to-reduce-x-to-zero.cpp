class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum= 0;
        
        for(auto it: nums){
            totalSum+= it;
        }
        
        int endSum = totalSum - x,maxLen =- 1,l = 0, r = 0,sum = 0;
        
        for(int r = 0; r < nums.size(); r++){
            sum+= nums[r];
            while( l<=r && sum> endSum){
                sum-= nums[l];
                l++;
            }
            if(sum == endSum){
                maxLen= max( maxLen , r-l+1 );
            }
        }
        
        return  maxLen == -1 ? -1 : nums.size()-maxLen;
    }
};