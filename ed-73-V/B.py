n = int(input())

f = "".join(('W' if i%2 else 'B') for i in range(n))
g = "".join(('B' if i%2 else 'W') for i in range(n))

for i in range(n):
    if i%2:
        print(f)
    else:
        print(g)