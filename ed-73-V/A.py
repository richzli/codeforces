q = int(input())

p = {}
a = 1
for i in range(30):
    p[a] = i
    a <<= 1

for i in range(q):
    n = int(input())
    s = list(map(int, input().split()))
    k = [0 for i in range(30)]
    for si in s:
        k[p[si]] += 1
    for i in range(p[2048]):
        k[i+1] += k[i] // 2
    print("YES" if k[p[2048]] > 0 else "NO")
