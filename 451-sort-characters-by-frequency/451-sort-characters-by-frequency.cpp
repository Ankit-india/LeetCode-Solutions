class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        
        for(auto x: s){
            freq[x]++;
        }
        
        priority_queue<pair<int,char>> maxHeap;
        
        for(auto x: freq){
            maxHeap.push({x.second, x.first});
        }
        
        string ans = "";
        while(maxHeap.size() > 0){
            auto temp = maxHeap.top();
            for(int i = 0; i < temp.first; i++){
                ans += temp.second;
            }
            maxHeap.pop();
        }
        return ans;
    }
};