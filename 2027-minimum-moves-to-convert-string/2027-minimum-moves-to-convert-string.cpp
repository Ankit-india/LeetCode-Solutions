class Solution {
public:
    int minimumMoves(string s) {
        int i = 0, count = 0, n = s.length();
        while(i < s.length()) {
            if(s[i] == 'X') {
                count += 1;
                i += 3;
            }
            else i += 1;
        }
        return count;
    }
};