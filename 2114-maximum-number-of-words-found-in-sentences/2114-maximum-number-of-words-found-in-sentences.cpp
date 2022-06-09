class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = INT_MIN;
        for(auto x : sentences){
            int temp = 1;
            for(auto y : x){
                if(y == ' '){
                    temp++;
                }
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};