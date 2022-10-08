class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[nums.size() - 1];
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size() - 2; i++){
            int a = i + 1;
            int b = nums.size() - 1;
            
            while(a < b){
                int currSum = nums[i] + nums[a] + nums[b];
                if(currSum > target){
                    b -= 1;
                }
                else{
                    a += 1;
                }
                if(abs(currSum - target) < abs(res - target)){
                    res = currSum;
                }
            }
        }
        return res;
    }
};