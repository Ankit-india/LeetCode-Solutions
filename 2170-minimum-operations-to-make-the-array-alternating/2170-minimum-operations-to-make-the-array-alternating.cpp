class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> e, o;
        for (int i = 0; i < nums.size(); i++){
            if (i % 2) o[nums[i]]++;
            else e[nums[i]]++;
        }
        pair<int, int> p1 = {0, 0}, p2 = {0, 0}, p3 = {0, 0}, p4 = {0, 0}; 
		
        for (auto m : e) {
            if (m.second > p1.second) {
                p2 = p1;
                p1 = m;
            }
            else if (m.second > p2.second)
                p2 = m;
        }
        
        for (auto m : o) {
            if (m.second > p3.second) {
                p4 = p3;
                p3 = m;
            }
            else if (m.second > p4.second)
                p4 = m;
        }
        
        int cnt1 = 0, cnt2 = 0;
        if (p1.first == p3.first) {                        
            cnt1 = p1.second + p4.second;
            cnt2 = p2.second + p3.second;
        }
        else cnt1 = p1.second + p3.second;
        
        return nums.size() - max(cnt1, cnt2);
    }
};
  