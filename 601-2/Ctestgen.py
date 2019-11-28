import random

n = 5000

l = list(range(n))
random.shuffle(l)

print(l)

trips = []
for i in range(len(l)-2):
    k = l[i:i+3]
    random.shuffle(k)
    trips.append(k)
random.shuffle(trips)

f = open("in.in", "w")
f.write(str(n) + "\n")
for t in trips:
    f.write(" ".join(map(str, t)) + "\n")