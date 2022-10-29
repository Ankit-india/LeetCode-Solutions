class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) 
    {
        int n = plantTime.size();
        vector<pair<int, int>> temp(n);        
        
        for(int i=0; i<n; i++) 
        {
			
            temp[i] = {growTime[i], plantTime[i]};
        }
        sort(temp.begin(), temp.end(),  greater<pair<int, int>>());
        
        int day = 0;
        int ans = 0;
        
        for(int i=0; i<n; i++) 
        {
            day += temp[i].second;
            ans = max(ans, day+temp[i].first);
        }
        
        return ans;
    }
};