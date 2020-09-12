import sys

def solve(n):
    a = 1
    b = 2
    while b <= n:
        print("? {} {}".format(b, a))
        sys.stdout.flush()
        c = int(input())
        if c == 0:
            b += 1
        elif c == 1:
            a = b
            b += 1
        else:
            a = b + 1
            b = a + 1
    return a

n = int(input())
one = solve(n)

arr = ["!"]
while len(arr) <= n:
    if len(arr) == one:
        arr.append(1)
    else:
        print("? {} {}".format(len(arr), one))
        sys.stdout.flush()
        arr.append(int(input()))
print(*arr)



