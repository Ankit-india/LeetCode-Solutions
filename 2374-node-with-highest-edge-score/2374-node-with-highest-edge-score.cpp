class Solution {
public:
    int edgeScore(vector<int>& edges) {

        int ans = -1, ct = -1;
        vector<long long> v(edges.size());
        for(int i = 0; i < edges.size(); i++){
            v[edges[i]] += i;
            if(v[edges[i]] > ct){
                ct = v[edges[i]];
                ans = edges[i];
            }
            else if(v[edges[i]] == ct){
                ans = min(ans, edges[i]);
            }
        }
        return ans;
    }
};