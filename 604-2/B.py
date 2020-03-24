

t = int(input())
for i in range(t):
    n = int(input())
    p = list(map(lambda x:int(x)-1, input().split()))
    r = [0 for i in range(n)]
    for i in range(n):
        r[p[i]] = i
    a = ["0" for i in range(n)]

    for i in range(n):
        l = r[:i+1]
        if max(l)-min(l) == i:
            a[i] = "1"

    print("".join(a))