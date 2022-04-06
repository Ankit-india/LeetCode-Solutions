class Solution {
public:
    int GetRightMostSetBitPosition(int num) {
        for(int i = 0; i < 32; ++i) {
            int l = 1 << i;
            if((num & l)) return i;
        }
        return -1;
    }
    vector<int> singleNumber(vector<int>& nums) {
        int t = 0;
        // int[] res = new int[2];
        vector<int> ans(2);
        for(int i = 0; i < nums.size(); ++i){ 
            t ^= nums[i];
        }
        int l = 1 << GetRightMostSetBitPosition(t);
        for(int i = 0; i < nums.size(); ++i) {
            if((nums[i] & l) == 0){
                ans[0] ^= nums[i];
            }
            else {
                ans[1] ^= nums[i];
            }
        }
        return ans;
    }
};