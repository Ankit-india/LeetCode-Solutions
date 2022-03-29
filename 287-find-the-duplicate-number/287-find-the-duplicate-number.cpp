class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
        
        vector<int> t(nums.size() + 1);
        for(int i = 0; i <= nums.size(); i++){
            t[nums.at(i)]++;
            if(t[nums.at(i)] > 1){ 
                // cout << i;
                ans = nums.at(i);
                break;
            }
        }
        return ans;
    }
};