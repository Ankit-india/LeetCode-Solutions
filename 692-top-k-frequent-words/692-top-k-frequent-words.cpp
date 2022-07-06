class Solution {
public:
    struct comp{
    bool operator()(pair<int,string>&a, pair<int,string>&b){
        if(a.first==b.first)
            return a.second>b.second;
        
        return a.first<b.first;     
        }        
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int>m;
        
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }
        
        priority_queue<pair<int,string>, vector<pair<int,string>>,comp>pq;
        
        for(int i=0;i<words.size();i++){            
            if(m[words[i]]>=1)
            pq.push({m[words[i]],words[i]});
            m[words[i]]=0;
        }       
        
        vector<string>ans;
        
        while(ans.size()!=k){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};