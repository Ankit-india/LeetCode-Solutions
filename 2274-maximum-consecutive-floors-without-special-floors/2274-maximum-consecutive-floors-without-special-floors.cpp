class Solution {
public:
    int maxConsecutive(int b, int t, vector<int>& arr) {
        sort(arr.begin(), arr.end());
        // int ans = INT_MIN;
        
        // int i = 0;
//         while(i < arr.size() && b != t){
//             ans = max(ans, (b-arr[i]));
//             i++;
//             if(i < arr.size()){
//                 b = arr[i];
//             }
            
//         }
//         if(b != t){
//             ans = max(ans, b-t+1);
//         }
        int ans = arr[0]-b;
        int n = arr.size();
        for(int i = 1; i < n; i++){
            ans = max(ans, arr[i]-arr[i-1]-1);
        }
        ans = max(ans,t-arr[n-1]);
        if(ans==1)return 0;
        return ans;
    }
};