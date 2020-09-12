import math
t = int(input())

for i in range(t):
    l = input()
    a = list(map(int, input().split()))
    n = max(a)
    print(n, end = " ")
    del a[a.index(n)]

    while len(a) > 0:
        m = 1
        mi = 0
        for i in range(len(a)):
            g = math.gcd(a[i], n)
            if g > m:
                m = g
                mi = i
        n = m
        print(a[mi], end = " ")
        del a[mi]

    print()