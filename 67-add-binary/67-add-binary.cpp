class Solution {
public:
    
    string addBinary(string a, string b) {
        int ap = a.size() - 1;
        int bp = b.size() - 1;
        string ans = "";
        int cr = 0;
        while(ap >=0 || bp >=0){
            int sum = cr;
            
            if(ap >= 0) {
                sum += a[ap] - '0';
                ap--;
            }
            if(bp >= 0) {
                sum += b[bp] - '0';
                bp--;
            }
            cr = sum > 1 ? 1 : 0;
            ans += to_string(sum % 2);
        }
        if(cr){
            ans += to_string(cr);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};