import random
f = open("in.in", "w")

t = 2
f.write(str(t) + "\n")
for i in range(t):
    k = random.randint(5, 10)
    m = [(l + 1) for l in range(k)]
    random.shuffle(m)
    print(m)
    f.write(str(k) + "\n")
    f.write(" ".join(map(str, [max(m[:p+1]) for p in range(len(m))])) + "\n")

f.close()