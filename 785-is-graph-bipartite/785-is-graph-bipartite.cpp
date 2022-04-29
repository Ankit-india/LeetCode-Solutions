class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,0);
        
        for(int i = 0; i < n; i++){
            if(color[i] == 1 || color[i] == -1){
                continue;
            }
            queue<int>q;
            q.push(i);
            color[i] = 1;
            
            while(!q.empty()){
                int temp = q.front();
                q.pop();
                for(auto it: graph[temp]){
                    if(color[it] == 0){
                        color[it] = -color[temp];
                        q.push(it);
                    }
                    if(color[it] == color[temp]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};