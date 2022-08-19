class Solution {
    // vector<int> merge()
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        for(auto x: nums1) arr.push_back(x);
        for(auto x: nums2) arr.push_back(x);
        
        sort(arr.begin(), arr.end());
        
        int n = arr.size() / 2;
        if(arr.size() % 2 != 0){
            return arr[n] * 1.0;
        }
        // cout <<  (arr[n]+ arr[n-1] )/ 2.0;
        return ( arr[n]+ arr[n-1] )/ 2.0;
    }
};