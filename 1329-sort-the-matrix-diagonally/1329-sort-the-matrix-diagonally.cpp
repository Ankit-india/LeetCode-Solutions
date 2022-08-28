class Solution {
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix[0].size(), vector<int>(matrix.size(), 0));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
         vector<int> k;
        int m = mat.size() , n = mat[0].size();
        for (int rw=0; rw<m; rw++)      
        {
            k.clear();
            for (int j=0,i=rw; j<n && i<m ; j++,i++) k.push_back(mat[i][j]);   
            sort(k.begin(),k.end());
            for (int j=0,i=rw; j<n && i<m ; j++,i++) mat[i][j]=k[j];          
        }
        for (int cl=1; cl<n; cl++)      
        {
            k.clear();
            for (int i=0, j=cl; j<n && i<m; i++, j++) k.push_back(mat[i][j]);   
            sort(k.begin(),k.end());
            for (int i=0, j=cl; j<n && i<m; i++, j++) mat[i][j] = k[i];        
        }
        return mat;
    }
};