class Solution {
public:
    bool reorderedPowerOf2(int n) {
         string s = to_string(n);
        sort(s.begin(),s.end());
		
        vector<string> arr;
        for(int i=0;i<=30;i++){
            int p = pow(2,i);
            arr.push_back(to_string(p));
        }
        
        for(int i=0;i<=30;i++){
            sort(arr[i].begin(),arr[i].end());
        }
        
        for(int i=0;i<=30;i++){
            if(arr[i] == s ) return true;
        }
        return false;
    }
};