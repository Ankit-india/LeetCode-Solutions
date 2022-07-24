class Solution {
    void setZero(vector<vector<int>>& arr, int r, int c){
        int m = arr.size();
        int n = arr[0].size();
        for(int i = 0; i < m; i++){
            if(arr[i][c] != 0){
                arr[i][c] = -1;
            }
        }
        for(int i = 0; i < n; i++){
            if(arr[r][i] != 0){
                arr[r][i] = -1;
            }
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool flag = false;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    setZero(matrix, i,j);
                    flag = true;
                }
            }
        }
        if(flag)
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == -1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};