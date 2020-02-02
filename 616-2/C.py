t = int(input().rstrip())

for i in range(t):
    n, m, k = map(int, input().rstrip().split())
    k = min(k, m-1)
    nums = list(map(int, input().rstrip().split()))

    pk = tuple(max(nums[i], nums[i+(n-m)]) for i in range(m))

    best = 0
    for j in range(k+1):
        best = max(best, min(pk[j:j+m-k]))

    print(best)