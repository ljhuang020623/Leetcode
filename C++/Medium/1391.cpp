#include<vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        struct Dir{
            int dr;
            int dc;
        };

        vector<vector<Dir>> dirs = {
            {},
            {{0, -1}, {0, 1}},      // type 1: left to right
            {{-1, 0}, {1, 0}},      // type 2: up to down
            {{0, -1}, {1, 0}},      // type 3: left to down
            {{0, 1}, {1, 0}},       // type 4: right to down
            {{0, -1}, {-1, 0}},     // type 5: left to up 
            {{0, 1}, {-1, 0}},      // type 6: right to up
        };
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;      
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        auto hasDirection = [&](int streetType, Dir target){
            for (auto d : dirs[streetType]){
                if (d.dr == target.dr && d.dc == target.dc){
                    return true;
                }
            }
            return false;
        };


        // start from {0, 0}
        q.push({0, 0});
        visited[0][0] = true;
        
        while (!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            if (r == m - 1 && c == n - 1) return true;
            
            int type = grid[r][c];
            for (auto d : dirs[type]){
                int nr = r + d.dr;
                int nc = c + d.dc;
                
                if (nr < 0 || nc < 0 || nr >= m || nc >= n){
                    continue;
                }
                if (visited[nr][nc]){
                    continue;
                }

                int neighborType = grid[nr][nc];
                Dir opposite_dir = {-d.dr, -d.dc};
                if (hasDirection(neighborType, opposite_dir)){
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return false;

    }
};