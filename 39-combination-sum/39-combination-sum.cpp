class Solution {
public:
    void helper(int idx, int target, vector<int>& cand, vector<vector<int>>& res, vector<int>& ans){
        
        // TC ---> 2^t * k; t--> number of picking up a particular element
        // aux SC ---> k * x ; Because actual space complesity dependes upon the no of combination formed 
        if(idx == cand.size()){
            if(target == 0){
                res.push_back(ans);
            }
            return;
        }
        if(target >= cand[idx]){
            ans.push_back(cand[idx]);
            helper(idx, target - cand[idx], cand, res, ans);
            ans.pop_back();
        }
        helper(idx+1, target, cand, res, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        helper(0,target,candidates,res,ans);
        return res;
    }
};