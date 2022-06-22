class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> pSum(n,0), sSum(n,0);
        
        pSum[0] = nums[0];
        for(int i = 1; i < n; i++){
            pSum[i] = nums[i] + pSum[i-1];
        }
        sSum[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            sSum[i] = nums[i] + sSum[i+1];
        }
        
        if(pSum[n-1] - nums[0]==0){
            return 0;
        }
        for(int i = 1; i < n-1; i++){
            if(pSum[i-1] == sSum[i+1]){
                return i;
            }
        }
        
        if(sSum[0] - nums[n-1]==0){
            return n-1;
        }
        return -1;
    }
};