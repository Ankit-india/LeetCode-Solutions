class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;
        
        priority_queue<int> q;
        
        for(auto x: s){
            mp[x]++;
        }
        
        for(auto it:mp){
            q.push(it.second);
        }
        
        
        if(q.size()==1)
            return 0;
        int ans=0;
        int next=q.top();
        while(!q.empty()){
            int a= q.top();
            q.pop();
            ans += a-next;
            if(next>0)
                next--;
            if(!q.empty() && q.top()<=next)
                next=q.top();
                
        }
        
        return ans;
        
        
        
        
    }
};