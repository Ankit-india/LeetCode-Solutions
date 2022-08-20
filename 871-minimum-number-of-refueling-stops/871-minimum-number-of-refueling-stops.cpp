class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int ans = 0;
        int i = 0;
        priority_queue<int>q;
        while( startFuel < target) {
            for(; i < stations.size() && stations[i][0] <= startFuel; i++){
                q.push(stations[i][1]);
            }
            if(q.empty()) return -1;
            startFuel += q.top();
            q.pop();
            ans++;
        }
        return ans;
    }
};