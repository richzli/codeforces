t = int(input())
for i in range(t):
    n = int(input())
    q = map(int, input().split())
    
    combo = []
    in_combo = [False for j in range(n+1)]
    index = 1
    last_num = 0
    fail = False

    for j in q:
        if j > last_num:
            combo.append(j)
            in_combo[j] = True
            last_num = j
        elif j == last_num:
            while in_combo[index] and index < last_num:
                index += 1
            if index >= last_num:
                fail = True
            combo.append(index)
            in_combo[index] = True
        else:
            fail = True
        
        if fail:
            print(-1)
            break

    if not fail:
        print(*combo)
