class Solution {
public:
    string reverseWord(string s){
        string ans = "";
        for(int i = s.size()-1; i >= 0; i--){
            ans += s[i];
        }
        return ans;
    }
    string reverseWords(string s) {
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            string temp = "";
            while(s[i] != ' ' && i < s.size()){
                temp += s[i];
                i++;
            }
            ans += reverseWord(temp);
            if(i < s.size()) ans += ' ';
        }
        return ans;
    }
};