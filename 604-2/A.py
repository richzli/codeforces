def getnot(lets):
    if lets == "a":
        return "b"
    elif lets == "b" or lets == "c":
        return "a"
    elif lets == "ab" or lets == "ba" or lets == "aa" or lets == "bb":
        return "c"
    elif lets == "bc" or lets == "cb" or lets == "cc":
        return "a"
    elif lets == "ac" or lets == "ca":
        return "b"
    else:
        return "a"

def generate(length, l, r):
    ret = ""
    prev = l
    for i in range(length):
        if i != length-1:
            ll = getnot(prev)
            ret += ll
            prev = ll
        else:
            ll = getnot(prev+r)
            ret += ll
    
    return ret

def find(s):
    poss = ""
    run = 0
    for let in s:
        if poss == "":
            if let == "?":
                run += 1
            else:
                poss += generate(run, "", let) + let
                run = 0
        else:
            if let == "?":
                run += 1
            else:
                poss += generate(run, poss[-1], let) + let
                run = 0
                if poss[-2] == poss[-1]:
                    return -1
    if poss != "":
        poss += generate(run, poss[-1], "")
    else:
        poss += generate(run, "", "")
                    
    return poss


t = int(input())
for i in range(t):
    s = input().rstrip()
    print(find(s))
