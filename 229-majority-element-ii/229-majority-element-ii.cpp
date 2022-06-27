class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size();
        int occ = floor(n / 3);
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++){
            freq[arr[i]]++;
        }
        vector<int> ans;
        for(auto x: freq){
            if(x.second > occ){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};