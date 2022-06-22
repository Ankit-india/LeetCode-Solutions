class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        if(n % 2 != 0) return false;

        unordered_map<int, int>mp;

        for(int i = 0; i < n; i++){
            arr[i] = arr[i] % k;
            arr[i] > 0 ? mp[arr[i]]++ : mp[-arr[i]]--;

        }
        if(mp[0] % 2 != 0) return false;
        
        for(int i = 0; i < n; i++){
            if(arr[i] != 0){
                if(mp[arr[i]] != mp[k - arr[i]]) return false; 
            }
        }
        return true;
    }
};