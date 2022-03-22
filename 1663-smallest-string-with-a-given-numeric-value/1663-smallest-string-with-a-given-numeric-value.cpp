class Solution {
public:
    string getSmallestString(int n, int k) {
        string s = "";
        int i = 0;
        while(i < n){
            s += 'a';
            i++;
        }
        k = k - n;
        int j = n - 1 ;
        while(k > 0){
            if(k < 25){
                s[j] = (char) ('a' + k);
                k = 0;
            }
            else{
                s[j] = 'z';
                k = k - 25;
            }
            j--;
        }
        return s;
    }
};