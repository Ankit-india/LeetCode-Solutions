
class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        int skip = 0;
        
        while(l < r){
            if(s[l] == s[r])
            {
                l++;
                r--;
            }
            else
            {
                skip++;
               l++; 
            }
        }
        
        l = 0;
        r = s.size() - 1;
        int skip1 = 0;
        
        while(l < r){
            if(s[l] == s[r])
            {
                l++;
                r--;  
            }
            else
            {
                skip1++;
                r--;  
            }
               
        }
        
        if(skip == 1 || skip1 == 1)   
            return true;
        if(skip == 0 || skip1 == 0)    
            return true;
        
        return false;
    }
};