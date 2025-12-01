from typing import List 
class Solution:
    def countStableSubarrays(self, capacity: List[int]) -> int:
        n = len(capacity)
        if n < 3: return 0
        pref = [0] * (n + 1)
        for i, v in enumerate(capacity):
            pref[i + 1] = pref[i] + v
        
        count = 0 
        for left in range(n - 2):
            right = n
            while right - left >= 3:
                R = right - 1
                if capacity[left] == capacity[R]:
                    total = pref[R + 1] - pref[left]
                    if total == 3 * pref[left]:
                        count += 1
                right -= 1
        return count 
if __name__ == '__main__': 
    sol = Solution()
    tests = [[9,3,3,3,9], [1,2,3,4,5], [-4,4,0,0,-8,-4]]
    for capacity in tests:
        ans = sol.countStableSubarrays(capacity)
        print(ans)