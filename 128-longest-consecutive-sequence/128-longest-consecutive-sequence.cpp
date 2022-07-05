class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp(nums.begin(),nums.end()); 
        
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i] - 1)!=mp.end()){
                continue;
            }
            else{
                int ct = 0;
                int curr = nums[i];
                
                while(mp.find(curr) != mp.end()){
                    ct++;
                    curr++;
                }
                
                ans = max(ans,ct);
            }
        }
        
        return ans;
    }
};