class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // using two pointers approach
        int i = 0;
        int j = 0;
        vector<int>temp;
        while(i < m and j < n){
            if(nums1[i] < nums2[j]){
                temp.push_back(nums1[i]);
                i++;
            }
            else{
                temp.push_back(nums2[j]);
                j++;
            }
            // cout << " ankit ";
        }
        while(i < m){
            temp.push_back(nums1[i]);
            i++;
        }
        while(j < n){
            temp.push_back(nums2[j]);
            j++;
        }
        
        for (auto x: temp){
            cout << x << " ";
        }
        nums1.clear();
        // cout << nums1.size();
        for(int i = 0; i < temp.size(); i++){
            nums1.push_back(temp[i]);
        }
    }
};