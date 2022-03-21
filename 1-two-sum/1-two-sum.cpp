class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        // for(int i = 0; i < nums.size(); i++){
        //     mp[nums.at(i)] = i;
        // }
        vector<int>ans;
        for(int i = 0; i < nums.size(); i++){
            int temp = target - nums.at(i);
            if(mp.find(temp) != mp.end()){
                ans.push_back(i);
                ans.push_back(mp[temp]);
                break;
            }
            mp[nums.at(i)] = i;
        }
        return ans;
    }
};