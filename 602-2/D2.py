def nextPowTwoPow(n):
    m = n
    count = 0
    while n > 0:
            n = n >> 1
            count += 1
    if m & (m-1):
        return count
    else:
        return count - 1

n = int(input())
seq = list(map(int, input().split()))
m = int(input())
reqs = [tuple(map(int, input().split())) for i in range(m)]
new_reqs = sorted(reqs)[::-1]
d = {r:-1 for r in new_reqs}

# generate min segment tree from sequence
l = len(seq)
layers = nextPowTwoPow(l)
seq.extend(float('inf') for i in range(2**layers - l))
tree = [seq]
while len(tree[0]) > 1:
    tree = [[min(tree[0][2*j], tree[0][2*j + 1]) for j in range(len(tree[0])//2)]] + tree

# update min segment tree
def update(ind, val):
    global tree
    tree[-1][ind] = val
    for i in range(1, layers):
        v = ind >> i
        tree[-(i+1)][v] = min(tree[-i][v*2], tree[-i][v*2+1])

# find min with right preference
def find():
    global tree
    ind = 0
    layer = 1
    while layer < len(tree):
        if tree[layer][ind] < tree[layer][ind+1]:
            ind *= 2
        elif tree[layer][ind] >= tree[layer][ind+1]:
            ind *= 2
            ind += 1
        layer += 1
    return ind

last_len = len(seq)
last_seq = [x for x in seq if x != float('inf')]
while len(new_reqs) > 0:
    r = new_reqs.pop(0)
    if r[0] == last_len:
        d[r] = last_seq[r[1]-1]
    else:
        last_len -= 1
        while last_len > r[0]:
            print(find())
            update(find(), float('inf'))
            last_len -= 1
        last_seq = [x for x in seq if x != float('inf')]
        d[r] = last_seq[r[1]-1]
    print(tree, r, d[r])

print(reqs)
for r in reqs:
    print(d[r])

# ran out of time while debugging, rip