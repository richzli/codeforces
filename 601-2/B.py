T = int(input())
for i in range(T):
    n, m = map(int, input().split())
    w = list(map(int, input().split()))
    
    if n != m or n == 2:
        print(-1)
    else:
        print(2*sum(w))
        for i in range(1, n):
            print(i, i+1)
        print(1, n)