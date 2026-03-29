def solution(A):
    A.sort()
    target = 1
    prev = None
    for x in A:
        if x <= 0:
            continue
        elif x == prev:
            continue
        prev = x 
        if x == target:
            target += 1
        if x > target:
            return target
    return target



print(solution([1, 3, 6, 4, 1, 2]))
[1, 1, 2, 3, 4, 5]
