# Complete the countSwaps function below.
def countSwaps(a):
    swaps = 0
    for i in range(0, len(a)):
        for j in range(0, len(a)-i-1):
            if a[j] > a[j+1]:
                swaps += 1
                t = a[j]
                a[j] = a[j+1]
                a[j+1] = t
    print 'Array is sorted in ' + str(swaps) + ' swaps.'
    print 'First Element: ' + str(a[0])
    print 'Last Element: ' + str(a[len(a)-1])