class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> arr(nums);
        int ans = 0;
        sort(arr.begin(), arr.end());
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            if(arr[l] != nums[l]){
                break;
            }
            l++;
        }
        while(0 <= r){
            if(arr[r] != nums[r]){
                break;
            }
            r--;
        }
        if(r > 0 || l < nums.size()){
            ans = r - l + 1;
            
        }
        return ans;
    }
};