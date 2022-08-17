class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        if(words.size() == 1) return 1;
        vector<string> arr{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string>st;
        
        for(int i = 0; i < words.size(); i++){
            string temp = "";
            for(int j = 0; j < words[i].size(); j++){
                temp += arr[words[i][j] - 'a'];
            }
            st.insert(temp);
        }
        return st.size();
    }
};