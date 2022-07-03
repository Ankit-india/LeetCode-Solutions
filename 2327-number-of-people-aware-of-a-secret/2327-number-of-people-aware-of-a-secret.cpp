class Solution {
public:
    int mod = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod = 1e9 + 7;
        vector<int> arr(n + 1, 0);
        arr[0] = 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + delay; j <= n && j < i + forget; j++){
                arr[j] = (arr[j] + arr[i]) % mod;
            }
            if (i + forget >= n){
                ans = (ans + arr[i]) % mod;
            }
        }
        return ans;
    }
};