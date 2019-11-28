n = int(input())

for i in range(n):
    c, s = map(int, input().split())
    d = s // c
    r = s % c
    print((d**2)*(c-r) + ((d+1)**2)*(r))