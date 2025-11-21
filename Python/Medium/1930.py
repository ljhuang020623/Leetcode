class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        alphabet= "abcdefghijklmnopqrstuvwxyz"
        count = 0
        for c in alphabet:
            left = s.find(c)   # return the smallest index that contains c
            right = s.rfind(c) # return the largest index that contains c

            # if c is not found then returns -1 also left and right cant be the same index
            if left == -1 or left == right:
                continue
            
            seen = set()
            # iterate through the middle char 
            for i in range(left + 1, right):
                if s[i] not in seen:
                    count += 1
                    seen.add(s[i])
        return count 
    

        # GPT answer, ord will get the ASCII
        # returns the number correspoding the uniode code of a specified character
        # for c in map(chr, range(ord('a'), ord('z') + 1)):

        
sol = Solution()
tests = ["aabca", "adc", "bbcbaba"]
for s in tests:
    ans = sol.countPalindromicSubsequence(s)
    print(ans)