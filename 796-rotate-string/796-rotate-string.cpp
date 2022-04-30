class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        string txt = s + s;
        
        int n = txt.size()-goal.size();
        
        for(int i = 0; i < n; i++){
            if(txt.substr(i, goal.size()) == goal){
                return true;
            }
        }
        return false;
    }
};