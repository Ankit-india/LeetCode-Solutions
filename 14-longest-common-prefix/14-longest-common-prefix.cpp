class Solution {
public:
    int findMinStringLength(vector<string>& arr){
        int res = INT_MAX;
        
        for(string x: arr){
            if(x.size() < res){
                res = x.size();
            }
        }
        return res;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n = findMinStringLength(strs);
        string ans = "";
        for(int i = 0; i < n; i++){
            char curr = strs[0][i];
            
            for(int j = 0; j < strs.size(); j++){
                if(strs[j][i] != curr){
                    return ans;
                }
            }
            ans += curr;
        }
        return ans;
    }
};