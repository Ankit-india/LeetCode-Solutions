class Solution {
public:
    int dir[5]={1,0,-1,0,1};
    int minimumEffortPath(vector<vector<int>>& ht)
    {
        int m = ht.size();
        int n = ht[0].size();
        // MIN heap
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0, 0, 0});//eff,row,col
        while(!pq.empty())
        {
            vector<int> v = pq.top();
            pq.pop();
            int eff = v[0];
            int x = v[1];
            int y = v[2];
            if(x == m-1 && y == n-1){
                return eff;
            }
            if(x < 0|| y < 0 || x >= m || y >= n || ht[x][y] == 0){
                continue;
            }
            for(int i = 0; i < 4; i++){
                int nx = x + dir[i];
                int ny = y + dir[i+1];
                if(nx <= m-1 && ny <= n-1 && nx >=0 && ny>=0)
                pq.push({max(eff, abs(ht[x][y]-ht[nx][ny])), nx, ny});
                
            }
            ht[x][y]=0;
        }
        
        return 0;
    }
};