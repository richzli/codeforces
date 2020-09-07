def solve(n, k, s):
    a = [None for i in range(k)]
    for i in range(len(s)):
        j = i % k
        if not a[j] and s[i] != "?":
            a[j] = s[i]
        elif a[j] != s[i] and s[i] != "?":
            return "NO"
    
    z, o = 0, 0
    for i in range(k):
        if a[i] == "0":
            z += 1
        if a[i] == "1":
            o += 1
    
    return "YES" if (z <= k//2 and o <= k//2) else "NO"

t = int(input())

for i in range(t):
    n, k = map(int, input().split())
    print(solve(n, k, list(input())))