class Solution {
public:
    int kInversePairs(int n, int k) {
        int f1[1000 + 1] = {0};
        int f2[1000 + 1] = {0};
        f1[0] = 1;
        for (int curN = 2; curN <= n; curN++) {
            const auto &prevF = (curN % 2 == 0) ? f1 : f2;
            auto &curF = (curN % 2 == 0) ? f2 : f1;
            const int prevMaxK = calcMaxK(curN - 1);
            const int maxK = std::min(k, calcMaxK(curN));
            for (int curK = 0; curK <= maxK; curK++) {
                int newVal = (curK > 0) ? curF[curK - 1] : 0;
                newVal = (newVal + prevF[curK]) % MOD_VALUE;
                if (curK - curN >= 0) {
                    newVal -= prevF[curK - curN];
                    if (newVal < 0) newVal += MOD_VALUE;
                }
                curF[curK] = newVal;
            }
        }
        const auto finalF = (n % 2 == 0) ? f2 : f1;
        return finalF[k];
    }
    
    int calcMaxK(const int n) {
        return (1 + (n-1)) * (n-1) / 2; 
    }
    
    const int MOD_VALUE = 1000000000 + 7;
};