from typing import List
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        num_dict = {}
        for i in nums:
            if i in num_dict:
                num_dict[i] += 1
                if num_dict[i] >= 2:
                    return True
            else:
                num_dict[i] = 1
        return False


