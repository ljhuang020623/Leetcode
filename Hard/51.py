from typing import List
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        # base cases
        if n == 1:
            return [["Q"]]
        if n == 2 or n == 3:
            return []










if __name__ == '__main__': 
    pass




# [".Q..",    ["..Q.",
#  "...Q",     "Q...",
#  "Q...",     "...Q",
#  "..Q."]     ".Q.."]
# first thought is to choose a spot 