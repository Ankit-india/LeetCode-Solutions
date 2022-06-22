class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        vector<pair<int, string>> temp;
        
        for(int i=0;i<nums.size();i++){
            temp.push_back(make_pair(nums[i].size(), nums[i]));
        }
        sort(temp.rbegin(), temp.rend());
        return temp[k-1].second;
        
    }
};