class Solution {
public:
    void ankit(int o, int c, string op, vector<string>& res){
        if(o == 0 && c == 0){
            res.push_back(op);
            return ;
        }
        
        if(o != 0){
            string temp = op;
            temp += '(';
            ankit(o-1,c,temp,res);
        }
        if(c > o){
            string temp = op;
            temp += ')';
            ankit(o,c-1,temp, res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        ankit(n,n,"",ans);
        return ans;
    }
};