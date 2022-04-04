class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        
        int size = 1 << n; // size of power set 
        
        unordered_set<string> st;
        
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        for(int j = 0; j < size; ++j){
            vector<int> vec;
            string temp = "";
            for(int i = 0; i < n; i++){
                if((j >> i) & 1){
                    vec.push_back(nums[i]);
                    temp += to_string(nums[i])+",";
                }
            }
            if(!st.count(temp)){
              ans.push_back(vec);
              st.insert(temp);  
            }
        }
        
        return ans;
    }
};