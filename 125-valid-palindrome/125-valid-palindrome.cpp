class Solution {
public:
//     bool checkPalindrome(string s, int l, int r){
//         if(l >= r) return true;
        
//         if(s[l] == s[r]){
//             return checkPalindrome(s, l + 1, r - 1);
//         }
//         else{
//             return false;
//         }
        
//     }
    bool isPalindrome(string s) {
        // int l = 0, r = s.size() - 1;
        string newStr = "";
        
        for(auto x: s){
            if(isalpha(x) || isdigit(x)){
                newStr += tolower(x);
            }    
        }
        // cout << newStr << endl;
        // return checkPalindrome(newStr,0,newStr.size() - 1);
        int l = 0, r = newStr.size() - 1;
        
        while(l <= r){
            if(newStr[l] != newStr[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};