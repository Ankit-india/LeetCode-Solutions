class Solution {
public:
    bool canChange(string start, string target) {
        string st = "";
        for(auto x: start){
            if(x != '_'){
                st += x;
            }
        }
        string sr = "";
        for(auto x: target){
            if(x != '_'){
                sr += x;
            }
        }
        if(st != sr) return false;
        
//         int ctLs = 0, ctrs = 0;
//         for(int i = 0; i < start.size(); i++){
//             if(start[i] == 'R'){
                
//                 ++i;
//                 while(start[i] == '_'){
                    
//                 }
//             }
//         }
        int n = start.size();
        vector<int> l(n,0),r(n,0);
        
        if(target[0]=='L') l[0]++;
        
        for(int i=1;i<n;i++){
            l[i]=l[i-1];
            if(target[i]=='L')l[i]++;
        }
        
        if(target[n-1]=='R') r[n-1]++;
        
        for(int i=n-2;i>=0;i--){
            r[i]=r[i+1];
            if(target[i]=='R')r[i]++;
        }
        
        int lcount=0;
        for(int i=0;i<n;i++){
            if(start[i]=='L'){
                lcount++;
                if(l[i]<lcount) return false;
            }
        }
        
        int rcount=0;
        for(int i=n-1;i>=0;i--){
            if(start[i]=='R'){
                rcount++;
                if(r[i]<rcount) return false;
            }
        }
        
        return true;
    }
};