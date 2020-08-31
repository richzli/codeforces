t = int(input())

def play(a):
    turn = True
    while True:
        last = -1
        m = 0
        for i in range(len(a)):
            if i != m:
                if a[i] > m:
                    m = a[i]
                    last = i
        if last == -1:
            return turn
        a[last] -= 1            
        turn = not turn
    return turn

for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    print("T" if play(a) else "HL")