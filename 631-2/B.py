t = int(input())

for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))

    solns = []

    c = sorted(p)
    d = 0
    e = 0
    f = False
    while not f and len(c) > 0:
        if len(c) >= 2:
            if c[0] == e + 1:
                if c[0] == c[1] == d+1:
                    d += 1
                    e += 1
                    c.pop(0)
                    c.pop(0)
                elif c[0] == c[1]:
                    f = True
                else:
                    e += 1
                    c.pop(0)
            else:
                f = True
        else:
            if c[0] == e+1:
                e += 1
                c.pop(0)
            else:
                f = True

    if f or d == 0:
        pass
    else:
        a = set(range(1, d+1))
        for i in range(d):
            a.discard(p[i])
        if len(a) == 0:
            solns.append((d, n-d))

        if d != n-d:
            a = set(range(1, d+1))
            for i in range(d):
                a.discard(p[-i-1])
            if len(a) == 0:
                solns.append((n-d, d))
    
    print(len(solns))
    for s in solns:
        print(*s)