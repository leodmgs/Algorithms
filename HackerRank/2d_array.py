# Complete the hourglassSum function below.
def hourglassSum(arr):
    c = 0
    s = 0
    m = -99
    while c < len(arr)-2:
        for l in range(0, len(arr)-2):
            lc = l
            while lc < l+3:
                if lc == l+1:
                    s += arr[lc][c+1]
                else:
                    s += reduce((lambda x, y: x + y), arr[lc][c:c+3])
                lc += 1
            if s > m:
                m = s
            s = 0
        c += 1
    return m