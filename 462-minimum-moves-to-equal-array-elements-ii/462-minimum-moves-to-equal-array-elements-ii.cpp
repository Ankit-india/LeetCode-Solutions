class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        // if size of nums is ODD
        
        // if(n & 1){
        int mid = nums[n / 2];
        for(int i = 0; i < n; i++){
            ans += abs(mid - nums[i]);
        }
        // }
        // // if size of nums is even
        // else{
        //     int mid  = nums[n/2];
        //     // cout << mid;
        //     for(int i = 0; i < n; i++){
        //         ans+= abs(mid - nums[i]);
        //     }
        // }
        return ans;
    }
};