class Solution {
public:
    string discountPrices(string sentence, int discount) {
        
        auto doit = [&](string& word) {
		
            int n(size(word));
            if (word[0] != '$' || n == 1)   return word;
            
            long long price = 0;
            for (int i=1; i<n; i++) {
                if (!isdigit(word[i]))  return word;
                price = price*10 + (word[i]-'0');
            }
            
            double discountPercentage = (100 - discount) / 100.0;
            stringstream ss2;
            ss2 << fixed << setprecision(2) << (discountPercentage * price);
            return "$" + ss2.str();
        };
        
        string word, res;
        stringstream ss(sentence);
        
        while (ss >> word) {
            res += doit(word)+" ";
        }
        
        res.pop_back();
        return res;
    }
};