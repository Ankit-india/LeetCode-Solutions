class Solution {
public:
//     string reverseString(string s) {
        
//         while(l<=r){
//             swap(s[l],s[r]);
//             l++;
//             r--;
//         }
//     }
    string reverseWords(string str) {
        int l = 0;
        int r = 0;
        string s = str;
        while(r < s.size()){
//             if(r == s.size()-1){
                
//             }
            if(s[r] != ' ' && r != s.size()-1){
                r++;
                continue;
            }
            // cout << r << endl;
                int temp = r-1;
            if(r == s.size()-1){
                // cout << s[l] << endl;
                temp++;
            }
            
            while(l <= temp){
                swap(s[l],s[temp]);
                l++;
                temp--;
            }
            l = r+1;
            r++;
        }
        return s;
    }
};