class Solution:
    def isValid(self, s: str) -> bool:
        pairs = {')': '(', ']': '[', '}': '{'}
        stack = []
        for char in s:
            if char in '([{':
                stack.append(char)
            else:
                if not stack:
                    return False
                last_bracket = stack.pop()
                if pairs[char] != last_bracket:
                    return False
        return not stack

if __name__ == '__main__': 
    sol = Solution()
    tests = ["()", "()[]{}", "(]", "([])", "([)]", '([)]']
    for s in tests:
        ans = sol.isValid(s)
        print(ans)
