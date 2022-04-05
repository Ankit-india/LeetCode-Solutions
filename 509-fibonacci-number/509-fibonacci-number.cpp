class Solution {
public:
    int helpFibbo(int n, vector<int>& arr){
        if(n == 0 || n == 1) return n;
        // int res = 0;
        if(arr[n] != -1){
            return arr[n];
        } 
        arr[n] = helpFibbo(n-1,arr) + helpFibbo(n-2,arr);
        return arr[n];
    }
    int fib(int n) {
        vector<int>trace(31,-1);
        return helpFibbo(n,trace);
    }
};