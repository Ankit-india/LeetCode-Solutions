class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == right){
            return left & right;
        }
        int ans = left;
        for(long long int i = left+1; i <= right; i++){
            ans = ans & i;
            if(ans == 0){
                break;
            }
        }
        return ans;
    }
};