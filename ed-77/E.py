n = int(input())
boxers = tuple(map(int, input().split()))
friend = boxers.index(-1)
greater = list(zip(boxers[friend+1:], range(friend+1, n)))

if friend == n-1:
    print(0)
else:
    cost = 0
    while -1 in boxers and len(boxers) > 1:
        cost += boxers[-1]
        boxers = boxers[:len(boxers)//2]
    print(cost)