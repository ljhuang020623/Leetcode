from typing import List
class Solution:
    def closestCost(self, baseCosts: List[int], toppingCosts: List[int], target: int) -> int:
        best_cost = baseCosts[0]

        def dfs(topping_index, total_cost):
            nonlocal best_cost
            diff_curr = abs(total_cost - target)
            diff_best = abs(best_cost - target)
            if diff_curr < diff_best or (diff_curr == diff_best and total_cost < best_cost):
                best_cost = total_cost
            if topping_index == len(toppingCosts):
                return 
            
            dfs(topping_index + 1, total_cost)
            dfs(topping_index + 1, total_cost + toppingCosts[topping_index])
            dfs(topping_index + 1, total_cost + toppingCosts[topping_index] * 2)

        for b in baseCosts:
            dfs(0, b)
        return best_cost
        
if __name__ == '__main__': 
    sol = Solution()
    tests = [
        ([1,7], [3,4], 10),
        ([2,3], [4,5,100], 18),
        ([3,10], [2,5], 9)
    ]
    for base, toppingCosts, target in tests:
        ans = sol.closestCost(base, toppingCosts,target)
        print(ans)
