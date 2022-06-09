class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size(); i++){
            int temp = target - nums.at(i);
            if(mp.find(temp) != mp.end()){
                ans.push_back(mp[temp]+1);
                ans.push_back(i+1);
                break;
            }
            mp[nums.at(i)] = i;
            
        }
        return ans;
    }
};