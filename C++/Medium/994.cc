#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = (int)grid.size(), n = (int)grid[0].size(), fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1) fresh++;
                if (grid[i][j] == 2) q.push({i, j});
            }
        }

        if (q.empty() || fresh == 0) return 0;

        int minute = 0;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while(!q.empty() && fresh > 0){
            int s = (int)q.size();
            // multiple source has to rotten simaltaniously
            while(s--){
                auto [r, c] = q.front();
                q.pop();
                // 4 direction
                for (int k = 0; k < 4; k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;

                    if (grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            minute++;
        } 
        if (fresh == 0) return minute;
        return -1;
    }
};