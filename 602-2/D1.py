n = int(input())
seq = list(map(int, input().split()))[::-1]
m = int(input())
reqs = [list(map(int, input().split())) for i in range(m)]
s = min(r[0] for r in reqs)

ks = {}
count = len(seq)
while count >= s:
    ks[count] = seq[::-1]
    seq.remove(min(seq))
    count -= 1

for r in reqs:
    print(ks[r[0]][r[1]-1])