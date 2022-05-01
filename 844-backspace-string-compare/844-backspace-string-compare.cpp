class Solution {
public:
    // bool backspaceCompare(string s, string t) {
    //     string st1 = "";
    //     for(auto x: s){
    //         if(x=='#' && st1.size() > 0){
    //             st1.pop_back();
    //         }
    //         else if(x == '#' && st1.size() < 0){
    //             continue;
    //         }
    //         else {
    //             st1 += x;
    //         }
    //     }
    //     string st2 = "";
    //     for(auto x: t){
    //         if(x == '#' && st2.size() > 0){
    //             st2.pop_back();
    //         }
    //         else if(x == '#' && st2.size() < 0){
    //             continue;
    //         }
    //         else {
    //             st2 += x;
    //         }
    //     }
    //     return st1 == st2;
    // }
    bool backspaceCompare(string s, string t) 
    {
        int i=0;    
        int j=0;
        
        for(int k=0;k<s.size();k++)
        {
            if(s[k]!='#')
            {
                s[i]=s[k];
                i++;
            }
            else if(i>0) i--;      
            
        }
         
        for(int k=0;k<t.size();k++)
        {
            
            if(t[k]!='#')
            {
                t[j]=t[k];
                j++;
            }
            else if(j>0) j--;             
     
        } 
              
        if(i!=j) return false;
        
        for(int k=0;k<i;k++)  
        {
            if(s[k]!=t[k]) return false;
        }
        return true;
    }
};