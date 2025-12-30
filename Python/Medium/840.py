from typing import List
class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:

        # helper method: return true if is Magic
        def isMagic(grid: List[List[int]], r: int, c: int) -> bool:
            if grid[r + 1][c + 1] != 5:
                return False
            nums = {1, 2, 3, 4, 5, 6, 7, 8, 9}
            for i in range(r, r + 3):
                for j in range(c, c + 3):
                    if grid[i][j] in nums:
                        nums.remove(grid[i][j])
                    else:
                        return False
                    
            # rows
            if grid[r][c] + grid[r][c+1] + grid[r][c+2] != 15: return False
            if grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2] != 15: return False
            if grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2] != 15: return False

            # cols
            if grid[r][c] + grid[r+1][c] + grid[r+2][c] != 15: return False
            if grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1] != 15: return False
            if grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2] != 15: return False

            # diagonals
            if grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != 15: return False
            if grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != 15: return False

            if not nums: 
                return True 
            else: 
                return False


        row = len(grid)
        column = len(grid[0])
        result = 0

        # early exit
        if row < 3 or column < 3:
            return 0
        
        for r in range(row - 2):
            for c in range(column - 2):
                if isMagic(grid, r, c):
                    result += 1
        return result






# a magic square filled with distinct numbers from 1 to 9 and each row, column and diagonals
# all have the same sum 