t = int(input())

for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    i = len(a)-1
    j = i

    while j > 0 and i >= 0:
        if a[j] >= 0:
            j -= 1
            if i >= j:
                i = j-1
        else:
            while i >= 0 and a[i] <= 0:
                i -= 1
            if i >= 0:
                m = min(a[i], -a[j])
                a[i] -= m
                a[j] += m

    print(sum(i for i in a if i > 0))