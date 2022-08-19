class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // O(NlogN)
        unordered_map<int, int> mp;
        for(auto x: nums) mp[x]++;
        
        for(int i = 0; i < nums.size(); i++){
            if(mp[nums[i]] != 0){
                mp[nums[i]]--;
                for(int j = 1; j < k; j++){
                    mp[nums[i]+j]--;
                    if(mp[nums[i]+j] < 0) {
                        // for(auto x: mp){
                        //     cout << x.first << " " << x.second << endl;
                        // }
                        return false;
                    }
                }
            }
        }
        return true;
    }
};