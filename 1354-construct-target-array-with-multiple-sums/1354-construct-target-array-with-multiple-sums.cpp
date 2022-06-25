class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum = 0;
        for(auto i : target){
            pq.push(i);
            sum += i;
        }
        while(pq.top() > 1){
            int curr = pq.top();
            long long rest = sum - curr;
            if(curr < rest+1 || rest == 0)
                return false;
            else{
                pq.pop();
                if(curr%rest == 0){
                    pq.push(rest);
                    sum = rest+rest;
                }
                else{
                    pq.push(curr%rest);
                    sum = rest+curr%rest;
                }
            }
        }
        return true; 
    }
};