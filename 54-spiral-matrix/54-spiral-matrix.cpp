class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowMin = 0;
        int rowMax = matrix.size() - 1;
        
        // cout << matrix[0].size();
        vector<int> al;
        int colMin = 0;
        int colMax = matrix[0].size() - 1;
        int count  = 0;
        while(count < matrix[0].size()*matrix.size()){
            // up
            for(int i = colMin;  i <= colMax && count < matrix[0].size() * matrix.size(); i++){
                al.push_back(matrix[rowMin][i]);
                count++;

            }
            rowMin++;
            //right
            for(int i = rowMin; i <= rowMax && count < matrix[0].size() * matrix.size(); i++){
                al.push_back(matrix[i][colMax]);
                count++;
            }
            colMax--;
            //bottom
            for(int i = colMax; i >= colMin && count < matrix[0].size() * matrix.size(); i--){
                al.push_back(matrix[rowMax][i]);
                count++;
            }
            rowMax--;
            //left
            for(int i = rowMax; i >= rowMin && count < matrix[0].size() * matrix.size(); i--){
                al.push_back(matrix[i][colMin]);
                count++;
            }
            colMin++;
        }
        return al;
    }
};