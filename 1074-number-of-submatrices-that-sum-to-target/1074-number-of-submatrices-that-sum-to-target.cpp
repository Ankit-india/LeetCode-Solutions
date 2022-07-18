class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
       int row=matrix.size(),col=matrix[0].size();
        
        if(row<1)
            return 0;
        //prefix sum 
        for(int r = 0; r < row; r++){
            for(int c = 1; c < col; c++){
                matrix[r][c]+=matrix[r][c-1];
            }
        }
        int count=0;
        for(int c1 = 0; c1 < col; c1++){
            for(int c2 = c1; c2 < col; c2++){
                unordered_map<int,int>mp;
                int sum = 0;
                mp[0] = 1;
                for(int r = 0; r < row; r++){
                    sum += matrix[r][c2] - (c1 > 0 ? matrix[r][c1-1] : 0);
                    int key = sum - target;          
                    if(mp.find(key)!=mp.end()){
                        count+=mp[key];
                    }
                    mp[sum]++;
                }
            }
        }
        return count++; 
    }
};