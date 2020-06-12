t = int(input())

for _ in range(t):
    n, x = map(int, input().split())
    a = sorted(list(map(int, input().split())))

    curr = 0

    while len(a) > 0:
        if a[0] == curr + 1:
            while len(a) > 0 and a[0] == curr + 1:
                a.pop(0)
        elif a[0] != curr + 1 and x > 0:
            x -= 1
        elif x <= 0:
            break
        curr += 1

    print(curr + x)