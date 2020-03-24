t = int(input())

def check(psort, phash):
    for j in range(len(phash)-len(passw)+1):
        pp = phash[j:j+len(psort)]
        pp = sorted(pp)
        if psort == pp:
            return True
    return False

for i in range(t):
    passw = input()
    psort = sorted(passw)
    phash = input()

    print("YES" if check(psort, phash) else "NO")
