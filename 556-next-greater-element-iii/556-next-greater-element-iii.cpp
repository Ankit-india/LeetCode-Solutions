class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        if(! next_permutation(str.begin(), str.end())) return -1;
        long ans= stol(str);
        if(ans > INT_MAX) return -1;
        
        return ans;
        
    }
};