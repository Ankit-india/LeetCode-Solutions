class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "", b = "";
        for(string x : word1) a += x;
        
        for(string x : word2) b += x;
        
        return a == b;
    }
};