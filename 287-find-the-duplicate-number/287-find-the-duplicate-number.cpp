class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> refer(nums.size(), 0);
        for(auto itr = nums.begin(); itr != nums.end(); itr++){
            if(refer[*itr] != 0 )
                return *itr;
            else
                refer[*itr] = 1;
        }
        return 0;
    }
};