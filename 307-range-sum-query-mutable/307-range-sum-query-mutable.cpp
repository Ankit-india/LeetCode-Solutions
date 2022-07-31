class NumArray {
    vector<int>arr;
public:
    int sum;  
    NumArray(vector<int>& nums) {
        arr=nums;
        sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
    }
    
    void update(int index, int val) {
        sum-=arr[index];   
        arr[index]=val;
        sum+=val;
        
    }
    
    int sumRange(int left, int right) {
        int res=sum; 
        for(int i=0;i<left;i++){  
            res-=arr[i];
        }
        for(int i=right+1;i<arr.size();i++){
            res-=arr[i];
        }
        return res;
    }
};