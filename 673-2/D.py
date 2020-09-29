def solve():
    n = int(input())
    a = [0] + list(map(int,input().split()))
    S = sum(a)
    if S%n != 0:
        print(-1)
        return
    
    avg = S//n

    to_print = []

    for i in range(2, n+1):
        d = a[i] // i
        r = a[i] % i
        if r > 0:
            to_print.append((1, i, i-r))
            d += 1
        to_print.append((i, 1, d))
    
    for i in range(2, n+1):
        to_print.append((1, i, avg))

    print(len(to_print))
    for item in to_print:
        print(*item)
    return

t = int(input())
for _ in range(t):
    solve()
