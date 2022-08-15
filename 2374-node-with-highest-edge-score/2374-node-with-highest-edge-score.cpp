class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int res = -1,count = -1;
        // int[] arr = new int[edges.length];
        vector<long long>arr(edges.size());
        for(int i=0;i<edges.size();i++){
            arr[edges[i]] += i;
            if(arr[edges[i]] > count){
                res = edges[i];
                count = arr[edges[i]];
            }else if(arr[edges[i]] == count) res = min(res,edges[i]);
        }
        
        return res;
        
        // int n = edges.size();
        // int ans = -1, ct = -1;
        // int v[n] = {0};
        // for(int i = 0; i < edges.size(); i++){
        //     v[edges[i]] += i;
        //     if(v[edges[i]] > ct){
        //         ct = v[edges[i]];
        //         ans = edges[i];
        //     }
        //     else if(v[edges[i]] == ct){
        //         ans = min(ans, edges[i]);
        //     }
        // }
        // return ans;
    }
};