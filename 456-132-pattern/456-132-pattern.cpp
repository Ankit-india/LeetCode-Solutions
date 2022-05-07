class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>st;
        
        int m = INT_MIN;
        
        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[i] < m){
                return true;
            }
            
            while(!st.empty() && st.top() < nums[i]){
                int temp = st.top();
                st.pop();
                m = temp;
            }
            st.push(nums[i]);
        }
        return false;
        
        // for(int i = 0; i < nums.size(); i++){
        //     for(int j = i + 1; j < nums.size(); j++){
        //         for(int k = j + 1; k < nums.size(); k++){
        //             if(nums[i] < nums[k]){
        //                 if(nums[k] < nums[j]){
        //                     return true;
        //                 }
        //             }
        //         }
        //     }
        // }
        // return false;
    }
};