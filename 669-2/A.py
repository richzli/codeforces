t = int(input())
for i in range(t):
    l = input()
    a = list(map(int, input().split()))
    c = sum(a)
    d = sum(a[i] for i in range(len(a)) if i%2)
    e = c - 2*d
    pairs = [a[i:i+2] for i in range(0, len(a), 2)]

    if len(pairs) > 1 and c != abs(e):
        tp = []

        if e < 0:
            cnt = 0
            for p in pairs:
                if cnt > e:
                    if p[0] == 0 and p[1] == 1:
                        cnt -= 1
                        if e % 2 and cnt != -1:
                            tp += [0]
                    else:
                        tp += p
                else:
                    tp += p
        elif e > 0:
            cnt = 0
            for p in pairs:
                if cnt < e:
                    if p[0] == 1 and p[1] == 0:
                        cnt += 1
                        if e % 2 and cnt != 1:
                            tp += [0]
                    else:
                        tp += p
                else:
                    tp += p
        else:
            tp = a
        print(len(tp))    
        print(*tp)
    else:
        if c == abs(e) and c != 0:
            print(str(len(a)-c) + "\n" + "0 "*(len(a)-c))
        else:
            print(len(a))
            print(*a)
        

