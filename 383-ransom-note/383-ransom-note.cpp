class Solution {
public:
    bool canConstruct(string r, string m) {
        vector<int>vec(26);
        
        for(int i = 0; i < m.size(); i++){
            vec[m[i] - 'a']++;
        }
        vector<int>vec1(26);
        
        for(int i = 0; i < r.size(); i++){
            vec1[r[i] - 'a']++;
        }
        
        for(int i = 0; i < r.size(); i++){
            if(vec1[r[i] - 'a'] > vec[r[i] - 'a'] ){
                return false;
            }
        }
        return true;
    }
};