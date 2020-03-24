n = int(input())
for i in range(n):
    days = 0
    r, g, b = map(int, input().split())

    v = [r, g, b]

    m = max(v)
    v.remove(m)
    if sum(v) <= m:
        print(sum(v))
    else:
        print(m + (sum(v) - m) // 2)