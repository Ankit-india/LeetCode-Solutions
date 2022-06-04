class Solution {
public:
    bool check(int i, int j, vector<string> cb, int n){
        // checking upper diagonal
        int dr = i;
        int dc = j;
        
        while(i >= 0 && j >= 0){
            if(cb[i][j] == 'Q') return false;
            i--;
            j--;
        }
        
        i = dr;
        j = dc;
        
        while(j >= 0){
            if(cb[i][j] == 'Q') return false;
            j--;
        }
        
        i = dr;
        j = dc;
        
        while(i < n && j >= 0){
            if(cb[i][j] == 'Q') return false;
            j--;
            i++;
        }
        return true;
    }
    void solve(int j, vector<string>& cb, vector<vector<string>>& ans, int n){
        if(j == n){
            ans.push_back(cb);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(check(i,j,cb,n)){
                cb[i][j] = 'Q';
                solve(j+1, cb, ans, n);
                cb[i][j] ='.'; // backtraking
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> b(n);
        string s(n, '.');
        for(int i = 0; i < n; i++){
            b[i] = s;
        }
        
        solve(0, b, ans, n);
        return ans;
    }
};