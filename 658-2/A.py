t = int(input())
for _ in range(t):
    input()
    a = set(map(int, input().split()))
    b = set(map(int, input().split()))
    p = False
    for i in a:
        if i in b:
            p = True
            print("YES\n1 " + str(i))
            break
    if not p:
        print("NO")