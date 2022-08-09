class Solution {
    int mod = 1e9+7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        if(arr.size() == 0) return 0;
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> mp;
        for(int  i =0; i < arr.size(); i++){
            long long ct = 1l;
            for(int j = 0; j < i; j++){
                if(arr[i] % arr[j] == 0 && mp.find(arr[i]/arr[j]) != mp.end()){
                    ct += mp[arr[j]] * mp[arr[i]/arr[j]];
                }
            }
            mp[arr[i]] = ct;
        }
        long long ans = 0l;
        for(auto x: mp){
            ans += x.second;
            // cout <<  x.first << " " << x.second << endl;
        }
        return (int)(ans % mod);
    }
};