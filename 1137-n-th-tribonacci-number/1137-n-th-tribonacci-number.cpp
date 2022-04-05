class Solution {
public:
    int tribonacci(int n) {
        vector<long long int> vec(40);
        vec[0] = 0, vec[1] = 1, vec[2] = 1;
        for(int i = 0; i < n; i++){
            vec[i+3] = vec[i] + vec[i+1] + vec[i+2];
        }
        return vec[n];
    }
};