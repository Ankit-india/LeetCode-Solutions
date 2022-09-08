class Solution {
    int help(int i,int j,vector<int>& piles,vector<vector<int>>&dp){
        if(i>j) return 0;
        int takestart=0,takeend=0;
        if(dp[i][j]!=-1) return dp[i][j];
        takestart=piles[i]-help(i+1,j,piles,dp);
        takeend=piles[j]-help(i,j-1,piles,dp);
        return dp[i][j]=max(takestart,takeend);
    }
public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>>dp(piles.size()+1,vector<int>(piles.size()+1,-1));
        return help(0,piles.size()-1,piles,dp)>0?true:false;
    }
};