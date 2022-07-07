class Solution {
public:
    int dp[101][101];
    bool solve(int i,int j,string temp,string &s1,string &s2,string &s3){
        if(i == s1.length() && j == s2.length() && i+j == s3.length()) 
            return temp == s3;
        else if(dp[i][j] != -1) 
            return dp[i][j];
        
        bool op1 = false,op2 = false;
        
        if(i < s1.size() && s1[i] == s3[i+j]){ 
            op1 = solve(i+1,j,temp + s1[i],s1,s2,s3);
        }
        
        if(j < s2.size() && s2[j] == s3[i+j]){ 
            op2 = solve(i,j+1,temp + s2[j],s1,s2,s3);
        }
        
        bool res = op1 || op2;
        return dp[i][j] = res;
    } 
    
    bool isInterleave(string s1, string s2, string s3){
        int n1 = s1.size(),n2=s2.size(),n3=s3.size();
        if(n1 + n2 != n3) return false;
        memset(dp,-1,sizeof dp);
        return solve(0,0,"",s1,s2,s3);
    }
};