class Solution {
    int check(vector<int>& arr, int i, int j, int turn){
        if(i > j) return 0;
        
        if(turn == 0) {
            return max((arr[i] + check(arr, i+1, j, 1)), (arr[j] + check(arr, i, j-1, 1)));
        }
        else{
            return min(check(arr, i+1, j, 0), check(arr,i, j-1, 0));
        }
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int p2 = 0;
        for(auto x: nums) p2 += x;
        
        int p1 = check(nums, 0, nums.size() - 1, 0);
        // cout << p1 << endl;
        p2 -= p1;
        
        return p1 >= p2;
    }
};