# Complete the arrayManipulation function below.
def arrayManipulation(n, queries):
    a = [0]*(n+1)
    for q in queries:
        a[q[0]-1] += q[2]
        a[q[1]] -= q[2]
    p = 0
    m = 0
    for i in range(0, n):
        p += a[i]
        if p > m: m = p
    return m