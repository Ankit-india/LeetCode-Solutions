class Solution {
public:
     bool canReplace(string &stamp,string &target,int pos){
        int m=stamp.size(),n=target.size();
        for(int i=0;i<m;i++){
            if(target[i+pos]!='?' && target[i+pos]!=stamp[i])
                return false;
        }
        return true;
    }
    
    
    int replace(string &stamp, string &target, int pos){
        int ct=0;
        int m=stamp.size(),n=target.size();
        for(int i=0;i<m;i++){
            if(target[i+pos]!='?'){
                ct++;
                target[i+pos]='?';
            }
        }
        return ct;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        
        vector<int> ans;
        
        int m=stamp.size(),n=target.size();
        
        int count=0;
        
        vector<int> vis(n+1,0);
        
        while(count!=n){
            bool flag=false;
            for(int i=0;i<=n-m;i++){
                if(!vis[i] && canReplace(stamp,target,i)){
                    vis[i]=1;
                    count+=replace(stamp,target,i);
                    flag=true;
                    ans.push_back(i);
                    if(count==n) break;
                }
            }
            if(!flag) return {};
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};