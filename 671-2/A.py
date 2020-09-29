t = int(input())

for _ in range(t):
    n = int(input())
    a = list(input())
    R = any(map(lambda x: int(x)%2, a[::2]))
    B = any(map(lambda x: int(x)%2, a[1::2]))

    print(2 if (n%2 and not R) or (not n%2 and B) else 1)