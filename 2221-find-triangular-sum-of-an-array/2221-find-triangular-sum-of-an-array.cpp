class Solution {
    
    vector<int> helperFunc(vector<int>& nums){
        vector<int> temp;
        for(int i = 1; i < nums.size(); i++){
            temp.push_back((nums[i-1] + nums[i])%10); 
        }
        
        return temp;
    }
public:
    int triangularSum(vector<int>& nums) {
        int ans = 0;
        vector<int> temp = nums;
        while(temp.size() != 1){
            temp = helperFunc(temp);
            // for(int i = 0; i < temp.size(); i++) cout << temp[i] << " " ;
            cout << endl;    
        }
        return temp[0];
    }
};