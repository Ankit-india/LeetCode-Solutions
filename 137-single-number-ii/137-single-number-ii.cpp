class Solution {
public:
    void update(vector<int>& arr, int n){
        for(int i = 0; i < 32; i++){
            int temp = n & (1<<i);
            if(temp){
                arr[i]++;
            }
        }
    }
    int numsBit(vector<int> sumArr){
        int res = 0;
        for(int i = 0; i < 32; i++){
            res += (sumArr[i] * (1 << i));
        }
        return res;
    }
    int singleNumber(vector<int>& nums) {
        vector<int> ct_arr(32,0);
        for(int x: nums){
            update(ct_arr,x);
        }
        for(int i = 0; i < 32; i++){
            ct_arr[i] = ct_arr[i] % 3;
        }
        return numsBit(ct_arr);
    }
};