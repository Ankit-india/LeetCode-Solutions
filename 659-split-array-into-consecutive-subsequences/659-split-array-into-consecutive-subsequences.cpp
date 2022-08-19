class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> mp,temp;
        for(auto x : nums) mp[x]++;
        
        for(auto x : nums){
            if(mp[x] == 0) continue;
            
            mp[x]--;
            if(temp[x-1] > 0){
                temp[x-1]--;
                temp[x]++;
            }
            else if(mp[x+1] != 0 && mp[x+2] != 0){
                mp[x+1]--;
                mp[x+2]--;
                temp[x+2]++;
            }
            else {
                return false;
            }
        }
        return true;
    }
};