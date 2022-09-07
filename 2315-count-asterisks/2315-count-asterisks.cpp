class Solution {
public:
    int countAsterisks(string s) {
        bool flag = true;
        int count = 0;
        for(auto x:s){
            if(x == '|') flag = !flag;
            if(flag && x == '*') count++;
        }
        return count;
    }
};