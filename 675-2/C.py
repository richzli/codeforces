n = input()

MOD = 10**9 + 7
total = 0
def add(num):
    global total
    total += num
    total %= MOD
def mult10(num):
    return (num << 3) + (num << 1)

K = []
k = 1
for i in range(1, len(n)):
    K.append(k)
    k = mult10(k) + 1
    k %= MOD

if len(n) > 1:
    k = 1
    l = 10
    left = int(n[0])
    right = int(n[-1])
    for i in range(1, len(n)):
        add((len(n)-i) * right)
        add(K[-i] * left)

        right += l * int(n[-(i+1)])
        right %= MOD
        left = mult10(left) + int(n[i])
        left %= MOD

        l = mult10(l)
        l %= MOD

    print(total)
else:
    print(0)