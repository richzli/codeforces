from sys import stdout
from math import log

n = int(input())
prime = [True for i in range(n+1)]
prime[1] = False
i = 2
while i*i <= n:
    if prime[i]:
        for j in range(i, n//i+1):
            prime[i*j] = False
    i += 1
l = [i for i in range(n+1) if prime[i]]

x = 1
for p in l:
    print(p)
    for j in range(int(log(n, p)), 0, -1):
        print("B", p**j)
        stdout.flush()
        b = int(input())

        print("A", p**j)
        stdout.flush()
        a = int(input())

        if a == 1 and b != 0:
            x *= p**j
            break

print("C", x)
stdout.flush()
