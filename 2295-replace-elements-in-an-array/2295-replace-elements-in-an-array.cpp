class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> mp;
        for(int i = 0;i < size(nums); ++i) {
            mp[nums[i]] = i;
        } 
        for(int i = 0; i < size(operations); ++i){
            int a = operations[i][0];
            int b = operations[i][1];
            int idx = mp[a];
            nums[idx] = b;
            mp[b] = idx; 
        }
        return nums;
    }
};