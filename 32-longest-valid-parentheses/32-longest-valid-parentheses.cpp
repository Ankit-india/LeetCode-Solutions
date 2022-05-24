class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0){
            return 0;
        }
        
        stack<int> st;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            // if(s[i] == ')')
            else
            {
                if(!st.empty()&&s[st.top()]=='(')
                    st.pop();
                else
                    st.push(i);
            }
            if(st.empty()){
                ans=max(ans,i+1);
            }
            else{
                ans=max(ans,i-st.top());
            }
        }
        return ans;
    }
};