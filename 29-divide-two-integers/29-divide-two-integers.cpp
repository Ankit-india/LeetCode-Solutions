class Solution {
public:
    int divide(int did, int div) {
        long long int dividend = did;
        long long int divisor = div;
        if(dividend <= INT_MIN && divisor == -1){
            return INT_MAX;
        }
        
        int s = +1;
        if(dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0){ 
            s=-1;
        }
        if(dividend < 0){
            dividend = -(dividend);
        }
        if(divisor<0){
            divisor = -(divisor);
        }
        long long int t=0;
        long long int ans=0;
        for(int i = 31; i >= 0; --i){
            if(t + (divisor << i) <= dividend){
                t += divisor << i;
                ans += 1 << i;
          
            }
        }
        return (s * ans);
   }
};