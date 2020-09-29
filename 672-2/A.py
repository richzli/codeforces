t = int(input())
for _ in range(t):
    int(input())
    a = list(map(int, input().split()))
    if a == list(reversed(sorted(a))) and len(set(a)) == len(a):
        print("NO")
    else:
        print("YES")