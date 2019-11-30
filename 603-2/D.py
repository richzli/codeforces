n = int(input())
l = [-1 for i in range(26)]

def union(a, b):
    global l
    if l[a] == -1:
        l[a] = a
    l[b] = l[a]

def find(a):
    global l
    if l[a] == a:
        return a
    l[a] = find(l[a])
    return l[a]

for i in range(n):
    passw = input()
    cur = ord(passw[0]) - 97
    union(cur, cur)
    passw = passw[1:]
    for letter in passw:
        num = ord(letter) - 97
        union(cur, num)
        cur = num

unique = [False for i in range(26)]
for p in range(len(l)):
    if l[p] != -1 and not unique[find(p)]:
        unique[find(p)] = True

print(sum(unique))
