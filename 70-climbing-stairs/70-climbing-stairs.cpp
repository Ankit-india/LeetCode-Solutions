class Solution {
public:
    int helper(int n, vector<int>& arr){
        if(n == 1 || n == 0){
            return 1;
        }
        if(arr[n] != -1){
            return arr[n];
        }        
        arr[n] = (helper(n-1, arr) + helper(n-2, arr));
        return arr[n];
    }
    int climbStairs(int n) {
        vector<int> trace(46,-1);
        
        return helper(n,trace);
    }
};