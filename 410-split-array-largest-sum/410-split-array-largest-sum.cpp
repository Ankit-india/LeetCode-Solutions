class Solution {
public:
    bool fun(vector<int>& arr, int mid, int m){
        int subArray = 1;
        int temp = 0;
        
        for(int x: arr){
            temp += x;
            
            if(temp > mid){
                subArray+=1;
                temp = x;
            }
        }
        return (subArray <= m);
    }
    int splitArray(vector<int>& nums, int m) {
        int low = INT_MIN, high = 0;
        
        for(auto x : nums){
            low = max(low,x);
            high += x;
        }
        
        int ans = INT_MAX;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(fun(nums,mid,m)){
                ans = min(ans,mid);
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};