# Complete the repeatedString function below.
def repeatedString(s, n):
    ls = len(s)
    ca = 0
    if n < ls:
        for mc in range(0, n):
            if s[mc] == 'a': ca += 1
        return ca
    for c in s:
        if c == 'a': ca += 1
    dr = n / ls
    ca = dr * ca
    pr = n % ls
    if pr > 0:
        for lc in s[0:pr]:
            if lc == 'a':
                ca += 1
    return ca