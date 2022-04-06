class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod = 1e9 + 7;
        long long int ans = 0;
        
        for(int i = 0; i < arr.size(); i++){
            vector<int> temp(101);
            for(int j = i + 1; j < arr.size(); j++){
                int diff = target - arr.at(i) - arr.at(j);
                if(diff >= 0 && diff <= 100 && temp[diff] > 0){
                    ans += temp[diff];
                    ans %= mod;
                }
                temp[arr[j]]++;
            }
        }
        return (int)ans;
    }
};