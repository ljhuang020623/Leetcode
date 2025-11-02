from typing import List 
class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        grid = [[0] * n for _ in range(m)] 
        # mark guards as 1 and walls as 2 first in grid
        for r, c in guards:
            grid[r][c] = 1
        for r, c in walls:
            grid[r][c] = 2
        # from left to right 
        for r in range(m):
            seeing = False
            for c in range(n):
                if grid[r][c] == 1:
                    seeing = True
                elif grid[r][c] == 2:
                    seeing = False
                elif seeing and grid[r][c] == 0:
                    grid[r][c] = 3
        # from right to left
        for r in range(m):
            seeing = False
            for c in range(n - 1, -1, -1):
                if grid[r][c] == 1:
                    seeing = True
                elif grid[r][c] == 2:
                    seeing = False
                elif seeing and grid[r][c] == 0:
                    grid[r][c] = 3
        # from top to bottom:
        for c in range(n):
            seeing = False
            for r in range(m):
                if grid[r][c] == 1:
                    seeing = True
                elif grid[r][c] == 2:
                    seeing = False
                elif seeing and grid[r][c] == 0:
                    grid[r][c] = 3
        # from bottom to top
        for c in range(n):
            seeing = False
            for r in range(m - 1, -1, -1):
                if grid[r][c] == 1:
                    seeing = True
                elif grid[r][c] == 2:
                    seeing = False
                elif seeing and grid[r][c] == 0:
                    grid[r][c] = 3
        count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    count += 1
        return count
        
            
        
        
if __name__ == '__main__': 
    sol = Solution()
    tests = [(4, 6, [[0,0],[1,1],[2,3]], [[0,1],[2,2],[1,4]]), (3, 3, [[1,1]], [[0,1],[1,0],[2,1],[1,2]])]
    for m, n, guards, walls in tests:
        ans = sol.countUnguarded(m, n, guards, walls)
        print(ans)
    