from typing import List
class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        left, right = 0, len(people) - 1
        boats = 0
        while left <= right:
            boats += 1
            if people[left] + people[right] <= limit:
                left += 1
            right -= 1
            
        return boats
if __name__ == '__main__': 
    sol = Solution()
    tests = [([1, 2], 3), ([3, 2, 2, 1], 3), ([3, 5, 3, 4], 5)]
    for people, limit in tests:
        ans = sol.numRescueBoats(people, limit)
        print(ans)


# Initial Thought:

# only 2 ppl are allow on one boat
# limit represent the max weight of one boat
# return minimum boat to carry every given person 

# Conclusion(2 pointer greedy):
# 1. choose the maximum and minimum weight people and then pair them if their weight exceed the boat limit,
#    then it means that maximum weight person has to be isolated hence u decrement the right pointer by 1 in people and go on and on
# 2. if the weight is equal to the limit then u simply increment the left pointer by 1 to iterate through the people list      