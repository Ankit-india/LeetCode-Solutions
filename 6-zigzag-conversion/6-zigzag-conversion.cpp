class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        int o = 2 * numRows - 2;
        if (o == 0) return s;
        
        vector<string> arr(numRows);
        for (int i=0; i<n; i++) {
            int row = i % o;
            if (numRows <= row) {
                row = o - row;
            }
            arr[row].append(1, s[i]);
        }
        
        string ans = "";
        for (auto pattern : arr) {
            ans += pattern;
        }
        return ans;
    }
};