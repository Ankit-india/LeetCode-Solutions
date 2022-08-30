class Solution {
    vector<int> fillArray(vector<int>& arr){
        vector<int> temp;
        temp.push_back(1);
        for(int i = 1; i < arr.size(); i++){
            temp.push_back(arr[i-1] + arr[i]);
        }
        temp.push_back(1);
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows == 1){
            return ans;
        }
        numRows--;
        while(numRows--){
            ans.push_back(fillArray(ans.back()));
        }
        return ans;
    }
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res = generate(rowIndex+1);
        return res[rowIndex];
    }
};