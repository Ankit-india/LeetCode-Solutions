class Solution {
public:
    int count(vector<int>& arr, int ele){
        int ct = 0;
        for(auto x : arr){
            if(x == ele){
                ct++;
            }
        }
        return ct;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int,int> > s;
        
        for(int i = 0; i<mat.size(); ++i)
        {
            int cnt = count(mat[i],1);
            
            s.insert({cnt,i});
        }
        
        vector<int> ans;
        
        for(auto i : s)
        {
            if(k == 0)
                break;
            ans.push_back(i.second);
            --k;
        }
        
        return ans;
    }
    // vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    //     vector<int> ans;
    //     map<int,int> temp;
    //     // cout << mat.size();
    //     for(int i = 0; i < mat.size(); i++){
    //         int count = 0;
    //         for(int j = 0; j < mat[i].size(); j++){
    //             if(mat[i][j] == 1){
    //                 count++;
    //             }
    //         }
    //         temp[i] = count;
    //         ans.push_back(count);
    //     }
    //     sort(ans.begin(), ans.end());
    //     for(auto x: temp){
    //         cout << x.first << " " <<  x.second  << endl;
    //     }
    //     for(int i = 0; i < k; i++){
    //         if(ans[i] ==  )   
    //     }
    //     return ans;
    // }
};