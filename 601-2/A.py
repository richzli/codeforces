def solve(a, b):
    diff = abs(a - b)
    count = 0
    
    count += diff // 5
    diff %= 5
    count += diff // 2
    diff %= 2
    count += diff

    return count

T = int(input())
for i in range(T):
    a, b = map(int, input().split())
    print(solve(a, b))