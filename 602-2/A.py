t = int(input())
for i in range(t):
    n = int(input())
    l = 0
    r = 10**9
    for j in range(n):
        a, b = map(int, input().split())
        if a > l:
            l = a
        if b < r:
            r = b
    if r < l:
        print(l-r)
    else:
        print(0)