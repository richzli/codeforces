q = int(input())

for i in range(q):
    a, b, c = map(int, input().split())
    t = a + b + c
    print(min(a, b, t//3))