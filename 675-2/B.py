t = int(input())
for _ in range(t):
    n, m = map(int, input().rstrip().split())
    mat = []
    for i in range(n):
        mat.append(list(map(int, input().rstrip().split())))
    
    total = 0
    for i in range(n//2):
        for j in range(m//2):
            elems = (mat[i][j], mat[n-i-1][j], mat[i][m-j-1], mat[n-i-1][m-j-1])
            total += min(sum(abs(x-a) for a in elems) for x in elems)
    
    if n % 2:
        for j in range(m//2):
            elems = (mat[n//2][j], mat[n//2][m-j-1])
            total += min(sum(abs(x-a) for a in elems) for x in elems)
    
    if m % 2:
        for i in range(n//2):
            elems = (mat[i][m//2], mat[n-i-1][m//2])
            total += min(sum(abs(x-a) for a in elems) for x in elems)

    print(total)