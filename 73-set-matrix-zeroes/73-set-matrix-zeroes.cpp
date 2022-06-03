class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int m=arr.size(),n=arr[0].size();
        bool r1 = false,c1=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==0){
                   if(i==0)r1 = true;
                    if(j==0)c1=true;
                    arr[i][0]=0;
                    arr[0][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(arr[i][0]==0 ||arr[0][j]==0){
                    arr[i][j]=0;
                }
            }
        }
        if(r1 ) {
            for(int i=0;i<n;i++){
                arr[0][i]=0;
            }
        }
        if(c1){
            for(int j=0;j<m;j++){
                arr[j][0]=0;
            }
        }
    }
};