n = int(input())

for i in range(n):
    S = int(input())
    l = [0 for i in range(26)]
    a = ord("a")
    for j in range(S):
        word = input()
        for let in word:
            l[ord(let)-a] += 1
    print("NO" if any(let%S for let in l) else "YES")