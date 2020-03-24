m, n, k, t = map(int, input().split())
soldiers = map(int, input().split())

traps = []
for i in range(k):
    l, r, d = map(int, input().split())
    traps.append((r-l, d))
traps = sorted(traps, reverse = True)

t -= n+1
t //= 2

diff = -1
for tr in traps:
    if tr[0] <= t:
        break
    diff = max(diff, tr[1])

print(len(tuple(x for x in soldiers if x >= diff))) 