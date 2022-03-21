class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> idx(26,0);
        
        for(int i = 0; i < s.length(); ++i){
            idx[s[i] - 'a']  = i;
        }
        vector<int> ans;
        
        int st = 0, e = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            e = max(e, idx[s[i] - 'a']);
            
            if( i == e)
            {
                ans.push_back(i - st + 1);
                st = i + 1;
            }
        }
        
        return ans;
    }
};