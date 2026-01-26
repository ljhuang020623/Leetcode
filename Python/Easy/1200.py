from typing import List
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        result = []
        min_diff = abs(arr[1] - arr[0])
        for i in range(len(arr) - 1):
            diff = arr[i + 1] - arr[i]
            if diff < min_diff:
                min_diff = diff
                result = [[arr[i], arr[i + 1]]]
            elif diff == min_diff:
                result.append([arr[i], arr[i + 1]])
        return result
    

