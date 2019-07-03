# Complete the minimumBribes function below.
def minimumBribes(q):
    bribes = 0
    chaotic = True
    while chaotic:
        chaotic = False
        s = 0
        while s < len(q)-1:
            if q[s] != s+1: # it's not in your original position
                offset = abs(q[s] - (s+1))
                if offset > 2: # it is chaotic
                    print 'Too chaotic'
                    return
                # else it isn't chaotic, do:
                if q[s] > q[s+1]:
                    t = q[s+1]
                    q[s+1] = q[s]
                    q[s] = t
                    bribes += 1
                chaotic = True
            s += 1
    print bribes