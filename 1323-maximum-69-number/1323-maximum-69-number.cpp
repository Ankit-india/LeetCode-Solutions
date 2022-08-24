class Solution {
    char changeDigit(char n){
        if(n == '9') return '6';
        return '9';
    }
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        int ans = num;
        
        for(int i = 0; i < s.size(); i++){
            s[i] = changeDigit(s[i]);
            ans = max(ans, stoi(s));
            s[i] = changeDigit(s[i]);
        }
        
        return ans;
    }
};