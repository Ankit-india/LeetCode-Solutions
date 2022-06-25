class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int ct = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if(i == 0 && nums[i] > nums[i+1]){
                ct++;
            }   
            if(i!=0 && nums[i] > nums[i+1]){
                ct++;
                if(nums[i + 1] < nums[i - 1]){
                     nums[i + 1] = nums[i];
                }
            }   

            if(ct > 1){
                return 0;
            }
        }
        return 1;
    }
};