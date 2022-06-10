class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length=s.size();
        int max=0;
    
        unordered_map<char,int>mp;
        for(int i = 0; i < length; i++)
        {
            int j = 0;
            while((i + j) < length && mp.find(s[i+j]) == mp.end())
            {
                mp[s[i+j]]++;
                j++;
            }
            if(j > max){
                max = j;
            }
            mp.clear();
        }
        
        return max;
    }
};