class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
//         vector<vector<int>> grid(m,vector<int>(n,0));
        
//         for(int i = 0; i < guards.size(); i++){
//             grid[guards[i][0]][guards[i][1]] = 1;
//         }
//         for(int i = 0; i < walls.size(); i++){
//             grid[walls[i][0]][walls[i][1]] = -1;
//         }
        
//         for(int i = 0; i< m; i++){
//             for(int j = 0; j < n; j++){
//                 if(grid[i][j] == 1){
//                     int temp = 0;
//                     for(int k = temp; k < m; k++){
//                         grid[k][j] = 1;
//                         if(grid[k][j] == -1) break;
//                     }
//                     temp = 0;
//                     for(int k = temp; k < n; k++){
//                         grid[i][k] = 1;
//                         if(grid[i][k] == -1)break;
//                     }
//                 }
//             }
//         }
//         int ans = 0;
//         for(int i = 0; i< m; i++){
//             for(int j = 0; j < n; j++){
//                 if(grid[i][j] == 0){
//                     ans++;
//                 }
//             }
//         }
        
//         return ans;
        
         vector<vector<pair<int, int>>> rows(m, vector<pair<int, int>>{{-1, 1}, {n, 1}}), cols(n, vector<pair<int, int>>{{-1, 1}, {m, 1}});
            for (auto &g : guards) {
                rows[g[0]].push_back({g[1], 0});
                cols[g[1]].push_back({g[0], 0});
            }
            for (auto &w : walls) {
                rows[w[0]].push_back({w[1], 1});
                cols[w[1]].push_back({w[0], 1});
            }
            for (auto &r : rows)
                sort(begin(r), end(r));
            for (auto &c : cols)
                sort(begin(c), end(c));
            int res = 0;
            for (int i = 0; i < m; ++i) {
                auto it_r = begin(rows[i]);
                for (int j = 0; j < n; ++j) {
                    it_r = lower_bound(it_r, end(rows[i]), pair<int, int>{j, 0});
                    auto it_c = lower_bound(begin(cols[j]), end(cols[j]), pair<int, int>{i, 0});
                    if (it_r->first == j && it_c->first == i)
                        continue;
                    if (it_r->second == 0 || it_c->second == 0 || prev(it_r)->second == 0 || prev(it_c)->second == 0)
                        continue;         
                    ++res;
                }
            }
            return res;
        
    }
};