from typing import List 
from collections import deque
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        queue = deque([0])
        visited = {0}
        while queue:
            room = queue.popleft()
            for key in rooms[room]:
                if key not in visited:
                    visited.add(key)
                    queue.append(key)
        return len(visited) == len(rooms)
        


if __name__ == '__main__': 
    sol = Solution()
    tests = [[[1],[2],[3],[]], [[1,3],[3,0,1],[2],[0]]]
    for rooms in tests:
        ans = sol.canVisitAllRooms(rooms)
        print(ans)

# Simple BFS implementation