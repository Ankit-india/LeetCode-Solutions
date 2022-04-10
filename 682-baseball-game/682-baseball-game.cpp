class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> arr;
        
        for(auto x: ops){
            if(x == "D"){
                arr.push_back(2 * arr.back());
            }
            else if(x == "C"){
                arr.pop_back();
            }
            else if(x == "+"){
                // int temp1 = arr.back();
                // arr.pop_back();
                // int temp2 = arr.back();
                // arr.pop_back();
                // arr.push_back(temp1 + temp2);
                arr.push_back(arr.back() + arr[arr.size() - 2]);
            }
            else
                arr.push_back(stoi(x));
        }
        
        return accumulate(arr.begin(), arr.end(), 0);
    }
};