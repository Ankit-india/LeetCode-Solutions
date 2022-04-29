class Solution {
public:  
    map<int, bool> check;
    map<pair<int,int>, bool> dp; 
    int lastPos = 0;
    
    bool solve(int pos,int jump){
        if(pos == lastPos){ 
            return true;
        }
        if(pos > lastPos || jump <= 0){
            return false;
        }
        if(dp.find({pos, jump}) != dp.end()){
            return dp[{pos,jump}]; 
        }
    if(check[pos]){
            return dp[{pos,jump}] = solve(pos+jump,jump) || solve(pos+jump+1,jump+1) || solve(pos+jump-1,jump-1);
        }
        return dp[{pos,jump}] = false;
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        lastPos = stones[n-1];
        for(auto x : stones){
            check[x]=1; 
            
        }
        if(stones[1] == 1){
            return solve(1,1);
        }
        return false;
    }
};