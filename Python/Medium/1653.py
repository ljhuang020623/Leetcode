class Solution:
    def minimumDeletions(self, s: str) -> int:
        a_right = s.count('a')
        b_left = 0
        ans = a_right
        for ch in s:
            if ch == 'a':
                a_right -= 1
            elif ch == 'b':
                b_left += 1
            ans = min(ans, a_right + b_left)
        return ans 
        
