t = int(input())
for _ in range(t):
    n, x = map(int, input().split())
    a = list(map(lambda y: int(y) - x, input().split()))
    s = sum(a)
    c = a.count(0)

    if not any(a):
        print(0)
    elif s == 0 or c:
        print(1)
    else:
        print(2)