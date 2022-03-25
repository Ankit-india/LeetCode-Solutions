class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> vec;
        int ans = 0;
        
        for(int i = 0; i < costs.size(); ++i){
            ans += costs[i][0];
            vec.push_back(costs[i][1] - costs[i][0]);
        }
        sort(vec.begin(),vec.end());
        for(int i=0; i<costs.size()/2; i++){
            ans += vec[i];
        }
        
        return  ans;
    }
};