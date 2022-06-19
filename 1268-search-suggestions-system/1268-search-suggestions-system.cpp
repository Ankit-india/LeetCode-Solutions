class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        int l = 0, r = products.size()-1;
            
        sort(products.begin(), products.end());
        for(int i = 0; i < searchWord.length(); i++){
            vector<string> out;
            char c = searchWord[i];
            
            
            while(l <= r && (products[l][i] != c)){
                l++;
            }
            while(l <= r && (products[r][i] != c)){
                r--;
            }
            int remain = min(3, (r - l + 1)) ;
            for(int j = 0; j < remain; j++){
                out.push_back(products[l+j]);
            }
            ans.push_back(out);
        }
        return ans;
    }
};