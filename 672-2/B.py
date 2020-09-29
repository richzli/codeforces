t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(lambda x: len(bin(int(x))), input().split()))
    k = [0 for i in range(40)]
    for b in a:
        k[b] += 1
    total = 0
    for b in k:
        total += b*(b-1)//2
    print(total)