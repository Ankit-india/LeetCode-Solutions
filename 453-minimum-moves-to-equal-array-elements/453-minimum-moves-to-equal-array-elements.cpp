class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        // int n = nums.size();
        // int ans = 0;
        // sort(nums.begin(), nums.end());    // O(NlogN)
        // // int temp = nums[n / 2];
        // for(int i = 1; i < n; i++){
        //     ans += abs(nums[0] - nums[i]);
        // }
        // // if(ans != 0)return ans+1;
        // return ans;
        
        // O(N)
        int ans = 0;
        int n = nums.size();
        int mn = (1e9 + 8), idx = 0;
        for(int i = 0; i < n; i++){
            if(mn > nums[i]){
                mn = nums[i];
                idx = i;
            }
        }
        for(int i = 0; i < n; i++){
            if(i != idx){
                ans+=(nums[i]-mn);
            }
        }
        return ans;
    }
};