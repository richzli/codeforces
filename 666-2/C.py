n = int(input())
a = list(map(int, input().split()))
b = [i*n for i in a]
b.pop(0)
if n > 1:
    print("1 1")
    print(-a.pop(0))
    print("2", n)
    for i in range(n-1):
        print(b[i]-a[i], end = " ")
    print("\n1", n)
    print("0", end = " ")
    for i in range(n-1):
        print(-b[i], end = " ")
else:
    print("1 1")
    print(-a[0])
    print("1 1\n0\n1 1\n0")