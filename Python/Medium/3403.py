from itertools import combinations
class Solution:
    def answerString(self, word: str, numFriends: int) -> str:
        best = '' 
        L = len(word)
        if numFriends == 1:
            return word
        # only for numFriends > 1
        for cuts in combinations(range(1, L), numFriends - 1):
            prev = 0
            for idx in cuts:
                part = word[prev:idx]
                if part > best:
                    best = part
                prev = idx
            last_part = word[prev:]
            if last_part > best:
                best = last_part
        return best

if __name__ == '__main__': 
    sol = Solution()
    tests = [("dbca", 2), ("gggg", 4)]
    for word, numFriends in tests:
        ans = sol.answerString(word, numFriends)
        print(ans)


# if numFriends = 2 then u will need the word to be cut into 2 parts menaing only 1 slice required 
