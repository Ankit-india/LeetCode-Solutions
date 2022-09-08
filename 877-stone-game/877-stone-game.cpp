class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return 1;
    }
};
/*
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
        int ans = help(0,piles.size()-1,piles,dp);
        for(int i = 0; i < piles.size()+1; i++){
            for(int j = 0; j < piles.size()+1; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return ans > 0;
    }
};
*/