class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<bool> arr(s.length(), false);
        arr[0] = true;
        int lastPossible = 0;
        for(int i = minJump; i < s.length(); ++i){
            if(arr[i - minJump] == true){
                lastPossible = i - minJump;
            }
            if(s[i] == '0' && i - minJump >= lastPossible && i - maxJump <= lastPossible){
                arr[i] = true;
            }
        }
        return arr[s.length() - 1];
    }
};