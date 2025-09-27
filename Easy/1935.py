class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        words = text.split(" ")
        count = len(words)
        for word in words:
            for ch in brokenLetters:
                if ch in word:
                    count -= 1
                    break
        return count
    
if __name__ == '__main__': 
    sol = Solution()
    tests = [("hello world", "ad"), ("leet code", "lt"), ("leet code", "e")]
    for text, brokenLetters in tests:
        ans = sol.canBeTypedWords(text, brokenLetters)
        print(ans)
