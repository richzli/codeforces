def adj(a, b):
    return len(a-b) == 1

def diff(a, b):
    return tuple(a-b)[0], tuple(b-a)[0]

n = int(input())
trips = [tuple(map(int, input().split())) for i in range(n-2)]
trips = list(map(set, trips))

nums = {}
for t in trips:
    for c in t:
        nums.update(c = nums.get(c, set()) | {t})

num = -1
for n in nums:
    if len(nums[n]) == 1:
        num = n
        break

sortd = [nums[num]]
cur = nums[num]
y, z = 0, 0, 0

for i in range(n-3):
    cur -= {num}
    cur = list(cur)
    nex = nums[cur[0]] & nums[cur[1]]
    sortd.append(nex)

# time ran out here

"""
t = trips.pop(0)
sortd = []

for trip in trips:
    if adj(t, trip):
        sortd.append(trip)
for trip in sortd:
    trips.remove(trip)
sortd.insert(1, t)
sortd.reverse()

#print(sortd)

if len(sortd) == 2:
    #print(sortd)
    i = 0
    while len(trips) > 0:
        i %= len(trips)
        if adj(sortd[-1], trips[i]):
            sortd.append(trips[i])
            trips.pop(i)
        else:
            i += 1
else:
    i = 0
    while len(trips) > 0:
        i %= len(trips)
        #print(trips[i], adj(currl, trips[i]), adj(currr, trips[i]))
        if adj(sortd[0], trips[i]):
            sortd.insert(0, trips[i])
            trips.pop(i)
            #print(sortd)
        elif adj(sortd[-1], trips[i]):
            sortd.append(trips[i])
            trips.pop(i)
            #print(sortd)
        else:
            i += 1

#print(sortd)

This solution is too slow because it runs in O(n^2) time.
"""

order = []
x = 0
y = 0
z = 0
for i in range(len(sortd)-1):
    a, b = diff(sortd[i], sortd[i+1])
    order.append(a)
    x = y
    y = z
    z = b

if len(sortd) == 3:
    x = tuple(sortd[0].intersection(sortd[1], sortd[2]))[0]
order.extend((x, y, z))

print(*order)


