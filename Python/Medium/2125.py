from typing import List 
class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        # O(n ^ 2)
        # list = []
        # total = 0
        # for i in range(len(bank)):
        #     count = 0
        #     for j in ra nge(len(bank[0])):
        #         if bank[i][j] == '1':
        #             count += 1
        #     if count != 0:
        #         list.append(count)
        # for k in range(len(list) - 1):
        #     total += (list[k] * list[k + 1])
        # return total
        list = []
        total = 0
        for rows in bank:
            count = rows.count('1')
            if count > 0:
                list.append(count)
        for i in range(len(list) - 1):
            total += (list[i] * list[i + 1])
        return total
if __name__ == '__main__': 
    sol = Solution()
    tests = [["011001","000000","010100","001000"], ["000","111","000"], ]
    for bank in tests:
        ans = sol.numberOfBeams(bank)
        print(ans)