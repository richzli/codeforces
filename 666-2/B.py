from math import log

n = int(input())
a = list(map(int, input().split()))
a.sort()

def search(t):
    m = sum(a)-n
    for i in range(2, t):
        N = 0
        k = 1
        for j in range(len(a)):
            N += abs(a[j]-k)
            k *= i
        m = min(m, N)
    return m     

if n > 50:
    print(sum(a)-n)
elif n == 1 or n == 2:
    print(a[0]-1)
else:
    print(search(int(10**(11/(n-1)))+1))