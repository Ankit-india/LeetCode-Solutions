class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // taking transpose
        for(int i = 0; i < matrix.size() - 1; i++){
            for(int j = i + 1; j < matrix.size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // swaping extreme columns by using two pointers/variable l and r
        int l = 0, r = matrix.size() - 1;
        while(l < r){
            for(int i = 0; i < matrix.size(); i++){
                swap(matrix[i][l],matrix[i][r]);
            }
            l++;
            r--;
        }
        
    }
};