# Optimal solution: O(n) time complexity
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = set()
        left = 0
        max_len = 0

        for right, ch in enumerate(s):
            while ch in seen:
                seen.remove(s[left])
                left += 1
            
            seen.add(ch)
            max_len = max(max_len, right - left + 1)
        return max_len
# This is the O(n ^ 2) answer not optimal 
# class Solution:
#     def lengthOfLongestSubstring(self, s: str) -> int:
#         max_len = 0
#         for i in range(len(s)):
#             seen = set()
#             temp = ''
#             temp += s[i]
#             seen.add(s[i])
#             max_len = max(max_len, len(temp))

#             for j in range(i + 1, len(s)):
#                 if s[j] not in seen:
#                     temp += s[j]
#                     max_len = max(max_len, len(temp))
#                     seen.add(s[j])
#                 else:
#                     max_len = max(max_len, len(temp))
#                     break
#         return max_len
               