class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        queue<int> less, greater;
        int ct = 0;
        for(auto x: nums){
            if(x < pivot){
                less.push(x);
            }
            else if(x == pivot) ct++;
            else {
                greater.push(x);
            }
        }
        int i = 0;
        while(!less.empty()){
            nums[i] = less.front();
            less.pop();
            i++;
        }
        while(ct--){
            nums[i] = pivot;
            i++;
        }
        while(!greater.empty()){
            nums[i] = greater.front();
            greater.pop();
            i++;
        }
        return nums;
    }
};