class Solution {
public:
    int firstUniqChar(string n) {
        unordered_map<char,int> m1;
        for(int i=0;i<n.length();i++){
            m1[n[i]]++;
        }
         for(int i=0; i<n.length(); i++){
                if(m1[n[i]] == 1)return i;
         }
        return -1;
    }
};