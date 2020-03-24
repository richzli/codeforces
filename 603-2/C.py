import math
t = int(input())
for i in range(t):
    n = int(input())
    nums = []
    s = int(math.sqrt(n))
    for c in range(1, s+1):
        if c != n//c:
            nums.append(n//c)
    if s == n//s:
        print(2*s)
    else:
        print(1 + 2*s)
    print(*range(s+1), *reversed(nums))