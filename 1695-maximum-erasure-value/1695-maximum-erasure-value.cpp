class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>ankit;
        int maxi=INT_MIN;
        int i = 0,j = 0;
        int sum = 0;
        while(i<nums.size()){
            while(j<i && ankit[nums[i]] !=0 ){
                ankit[nums[j]] = 0;
                sum -= nums[j++];
            }
            if(ankit[nums[i]]==0){
                ankit[nums[i]] = 1;
                sum += nums[i++];
            }
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};