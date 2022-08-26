class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int op = 0,ans = 1, prev = arr[0], l = 0;
        for(int i=1; i<n; i++){
            if(arr[i] == prev) l = i, op = 0;
            else if(arr[i] > prev){
                if(op == 1) l = i-1;
                op = 1;
            }
            else{
                if(op == -1) l = i-1;
                op = -1;
            }
            ans = max(ans, i-l+1);
            prev = arr[i];
        }
        return ans;
    }
};