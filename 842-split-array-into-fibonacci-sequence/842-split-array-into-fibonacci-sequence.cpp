class Solution {
    bool solve(string s,int start,vector<int>& ans){   
        if(start==s.size() && ans.size()>2){
            return true;
        } 
        long long int n = 0; 
        for(int i = start; i < s.size(); i++){ 
            n = n * 10 + s[i] - '0';    
            if(n < 0 || n > INT_MAX){
                return false;
            }
            if(ans.size()<2|| (long long int)ans.back()+(long long int)ans[ans.size()-2]==n){
                ans.push_back(n);
                if(solve(s,i+1,ans)){
                    return true;
                }
                ans.pop_back();
            }
            if(s[i]=='0' && i==start){
                return false;
            }
        }
        return false;
    }
public:
    vector<int> splitIntoFibonacci(string num) {
        
        vector<int> ans;
        solve(num,0,ans);
        return ans;
    }
};