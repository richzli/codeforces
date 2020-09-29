import math

t = int(input())
a = list(map(int, input().split()))
sz = 30
x = 0

def find_inversions(arr):
    if len(arr) == 1:
        return (arr, 0)
    
    left = find_inversions(arr[:len(arr)//2])
    right = find_inversions(arr[len(arr)//2:])
    leftarr = left[0]
    rightarr = right[0]
    combine = []
    inversions = left[1] + right[1]
    while len(leftarr) > 0 and len(rightarr) > 0:
        if leftarr[0] <= rightarr[0]:
            combine.append(leftarr.pop(0))
        else:
            inversions += len(leftarr)
            combine.append(rightarr.pop(0))
    if len(leftarr) > 0:
        combine += leftarr
    else:
        combine += rightarr
    return (combine, inversions)

minv = find_inversions(a)[1]
for j in range(sz, -1, -1):
    B = [a[i] ^ (x + (1<<j)) for i in range(len(a))]
    binv = find_inversions(B)

    if binv[1] < minv:
        x += (1 << j)
        minv = binv[1]

print(minv, x)
