class Solution {
public:
    int numTrees(int n) {
        // T(n) = ((2*n)C(n))/(n+1);
        // (n)C(r) = n!/(r!(n-r)!)
        vector<int>cat(n+1, 0);
        
        cat[0] = 1;
        cat[1] = 1;
        
        for(int i = 2; i<=n; ++i){
            for(int j = 0; j<i; ++j){                
                cat[i] += cat[j]*cat[i-j-1];
            }
        }
        
        return cat[n];
    }
};