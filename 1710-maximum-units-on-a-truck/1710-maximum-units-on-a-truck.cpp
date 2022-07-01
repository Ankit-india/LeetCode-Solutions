class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(
            boxTypes.begin(), boxTypes.end(), 
            [](auto &lft, auto &rgt) {
                 return lft[1] > rgt[1];
             }
        );
        int ans = 0;
        for(auto x : boxTypes)
        {
            if(truckSize >= x[0])
            {
                ans += x[0] * x[1];
                truckSize -= x[0];
            }
            else
            {
                ans += x[1] * truckSize;
                return ans;
            }
        }
        return ans;
    }
};