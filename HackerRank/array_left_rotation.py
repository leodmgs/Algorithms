# Complete the rotLeft function below.
def rotLeft(a, d):
    if d % len(a) == 0:
        return a
    acp = []
    f = d % len(a)
    for i in range(f, len(a)):
        acp.append(a[i])
    for j in range(0, f):
        acp.append(a[j])
    return acp