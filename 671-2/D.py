n = int(input())
spheres = sorted(list(map(int, input().split())))
shop = [0 for i in range(n)]
l = 0

while len(spheres) > 0:
    top = spheres[-1]
    i = -2
    while -i <= len(spheres):
        if spheres[i] != top:
            break
        i -= 1
    i += 1
    spheres = spheres[:i]

    while i < 0 and l < n:
        shop[l] = top
        l += 2
        i += 1
    
    if l >= n:
        spheres += [top] * -i
        break

l = 1
leftover = []
cnt = 0
while len(spheres) > 0:
    c = spheres.pop()
    if l < n-1 and shop[l-1] > c and shop[l+1] > c and shop[l] == 0:
        shop[l] = c
        l += 2
        cnt += 1
    else:
        leftover.append(c)

for i in range(n):
    if shop[i] == 0:
        shop[i] = leftover.pop()

print(cnt)
print(*shop)