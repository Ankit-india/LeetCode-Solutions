class Solution {
    int robHouse(vector<int>& nums){
        int n = nums.size();
        if(n == 1) return nums[0];
        int prev1 = nums[0], prev2=0;
        for(int i = 1; i < n; i++){
            int curi_take = nums[i];
            if(i > 1) curi_take += prev2;
            int curi_not_take = prev1;
            int curi = max(curi_take, curi_not_take);
            prev2 = prev1;
            prev1 = curi;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> arr1,arr2;
        for(int i = 0; i < n; i++){
            if(i != 0) arr1.push_back(nums[i]);
            if(i != n-1) arr2.push_back(nums[i]);
        }
        int a = robHouse(arr1);
        int b = robHouse(arr2);
        return max(a,b);
    }
};