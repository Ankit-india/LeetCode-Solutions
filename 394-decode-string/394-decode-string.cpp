class Solution {
public:
    string decodeString(string s) {
        string currString = "";
        int currNumber = 0;
        stack<pair<string,int>> st ;
        st.push({currString,currNumber}) ;
        
        for(int i=0;i<s.size();i++){
            if(s[i] == '['){
                st.push({currString,currNumber}) ;
                
                currString = "" ;
                currNumber = 0 ;
            }
            else if(s[i] == ']'){
                int prevNumber = st.top().second ;
                string prevString = st.top().first ;
                
                st.pop() ;
                
                for(int i=0;i<prevNumber;i++){
                   prevString+=currString ;
               }
                
                currString = prevString ;
                
            }
            else if(s[i] >='0' && s[i]<='9'){
                currNumber = currNumber*10 + s[i]-'0';
            } 
            else{
                currString+=s[i] ;
            }
        }
        
        return currString ;
    }
};