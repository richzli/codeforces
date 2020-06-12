n, m = map(int, input().split())
l = list(map(int, input().split()))

s = sum(l)
if s < n:
    print(-1)
else:
    i = 0
    while s > n:
        a = min(l[i] - 1, s - n)
        l[i] -= a
        s -= a
    t = 0
    for num in l:
        print(t+1, end = " ")
        t += num