class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int l = 0;
        int r = 0;
        
        for (int i = 0; i < k; ++i) {
            l += arr[i];
        }
        
        for (int i = arr.size() - 1; arr.size() - 1 - i < k; --i) {
            r += arr[i];
        }
        
        int ans = 0;
        int i = 0;
        int j = arr.size() - 1;
        
        while (k > 0) {
            if (l >= r) {
                ans += arr[i];
                l -= arr[i];
                r -= arr[j - k + 1];
                i++;
            } else {
                ans += arr[j];
                r -= arr[j];
                l -= arr[i + k - 1];
                --j;
            }
            --k;
        }
        
        return ans;
    }
};