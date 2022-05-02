class Solution {
public:
    bool binarySearch(vector<int>& arr, int target){
        int l = 0;
        int r = arr.size() - 1;
        // int idx = 0;
        while(l <= r){
            int mid=(l+r)/2;

            if(arr[mid]==target)
                return true;
            if(arr[mid] > target)
                r=mid-1;
            else
                l=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        for(auto& x: matrix){
          if(target >= x[0] && target<=x[n-1] && binarySearch(x,target))
              return true;            
        }
        return false;
    }
};