class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        for(int i = t.size() - 2; i >= 0; i--){
            for(int j = 0; j < n - 1; j++){
                int temp = t[i+1][j];
                if(j <= i){
                    temp = min(temp, t[i+1][j+1]);
                }
                t[i][j] += temp;
            }
            n--;
        }
        return t[0][0];
    }
};