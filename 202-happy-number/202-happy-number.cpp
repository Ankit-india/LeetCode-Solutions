class Solution {
public:
     int solve(int n){
        int ans = 0 ;
        while(n!=0){
            int rem = n%10;
            n = n/10;
            ans = ans + rem*rem;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_map<int,int> mp;
        mp[n]++;
        while(n!=1 && mp[n]!=2){
            n=solve(n);
            mp[n]++;
        }
        if(n==1) return true;
        return false;
    }
};