class Solution {
public:
    string longestPalindrome(string s) {
        int start=0,end=0;
        int l,r;
        for(int i=0;i<s.size();i++)
        {           
             l=i;
             r=i+1;
            while(l>=0&&r<s.size()&&s[l]==s[r])
            {
                if(r-l>end-start)
                {
                    start=l;
                    end=r;
                }
                l--;
                r++;
            }            
            l=i;
            r=i+2;
            while(l>=0&&r<s.size()&&s[l]==s[r])
            {
                if(r-l>end-start)
                {
                    start=l;
                    end=r;
                }
                l--;
                r++;
            }
        }
        string str;
        for(int i=start;i<=end;i++)
         str.push_back(s[i]);
        return str;    
    }
};