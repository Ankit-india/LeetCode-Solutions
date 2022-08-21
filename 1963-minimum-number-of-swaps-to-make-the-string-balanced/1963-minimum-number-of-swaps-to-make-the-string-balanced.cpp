class Solution {
public:
    int minSwaps(string s) {
        //min heap
        priority_queue <int, vector<int>, greater<int>> idx;
        
        // first we fill open brackets index in min heap
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '['){
                idx.push(i);
            }
        }
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ']'){
                if(i < idx.top()){
                    ans++;
                }
                else{
                    idx.pop();
                }
            }
        }
        return (ans+1)/2;
    }
};

// ] ] [ [ [ ] [ ] 