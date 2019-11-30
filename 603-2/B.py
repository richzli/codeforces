t = int(input())
for i in range(t):
    n = int(input())
    codes = []
    count = 0
    for j in range(n):
        PIN = int(input())
        if PIN not in codes:
            codes.append(PIN)
        else:
            count += 1
            PIN -= PIN % 10
            while PIN in codes:
                PIN += 1
            codes.append(PIN)
    
    print(count)
    print("\n".join("%04d" for k in range(len(codes))) % tuple(codes))