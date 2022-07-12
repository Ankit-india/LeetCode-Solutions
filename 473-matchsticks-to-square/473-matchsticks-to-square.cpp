class Solution {
public:
    vector<int> dp;
    bool dpSolver(int taken,long long sum,long long req,int n,vector<int>& matchsticks,int ans){
        
        if(sum==req){
            ans+=1;
            sum=0;
        }
        
        if(ans==4)
            return true;
        
        if(dp[taken]!=-1)
            return dp[taken];
        
        for(int i=0;i<n;i++){
            if(!(taken&(1<<i))&&(sum+matchsticks[i])<=req){
             bool p=dpSolver(taken|(1<<i),sum+matchsticks[i],req,n,matchsticks,ans);
                if(p)
                    return true;
            }
        }
        return dp[taken]=0;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n=matchsticks.size();
        dp.resize(1<<n,-1);
        int sum=0;
        for(auto it:matchsticks)
            sum+=it;
        if((sum%4)!=0)
            return false;
        sum/=4;
        return dpSolver(0,0,sum,n,matchsticks,0);
    }
};