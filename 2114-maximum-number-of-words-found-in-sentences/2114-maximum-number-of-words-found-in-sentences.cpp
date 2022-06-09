class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = INT_MIN;
        for(auto x : sentences){
            int i = 0; 
            int temp = 1;
            while(i < x.size()){
                if(x[i] == ' '){
                    temp++;
                }
                i++;
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};