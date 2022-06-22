class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>st;
        for(auto x: nums){
            st.insert(x);
        }
        
        nums.clear();
        nums.resize(0);
        
        for(auto x: st){
            nums.push_back(x);
        }
        int sz = nums.size();
        if (sz - 3 < 0){
            return nums[sz - 1];
        }
        return nums[sz - 3];
    }
};