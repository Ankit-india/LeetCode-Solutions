class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res=0;
        int prev=0;
        int curr=0;
        for(int i=0;i<bank.size();i++){
            int cnt=0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1') cnt++;
            }
            if(cnt!=0){
                prev=curr;
                curr=cnt;
            }
            if(curr!=0 && prev!=0 &&cnt){
                res+=prev*curr;
            }
        }
        return res;
    }
};