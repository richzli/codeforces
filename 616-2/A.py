t = int(input().rstrip())

for i in range(t):
    input()
    num = list(map(int, list(input().rstrip())))
    ebne = sum(num) % 2
    if ebne == 0:
        while len(num) > 0 and num[-1] % 2 == 0:
            num.pop()
        if len(num) == 0:
            print(-1)
        else:
            print("".join(map(str, num)))
    else:
        removed_odd = False
        while len(num) > 0 and (not removed_odd or (removed_odd and num[-1] % 2 == 0)):
            n = num.pop()
            if n % 2 == 1:
                removed_odd = True
        if len(num) == 0:
            print(-1)
        else:
            print("".join(map(str, num)))
