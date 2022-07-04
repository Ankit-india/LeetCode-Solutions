class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>lt(ratings.size(),1);
        vector<int>rt(ratings.size(),1);
        int ans=0;
        for(int i=1; i < ratings.size(); i++){
            if(ratings[i-1] < ratings[i])
                lt[i] = lt[i-1] + 1;
        } 
         for(int i = ratings.size()-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1])
                rt[i] = rt[i+1] + 1;
        }
        for(int i = 0; i < ratings.size(); i++){
            ans += max(lt[i],rt[i]);
        }
        return ans;    
    }
};