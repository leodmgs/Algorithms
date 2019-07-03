# Complete the minimumSwaps function below.
def minimumSwaps(arr):
    swaps = 0
    a_map = arr
    i = 0
    while i < len(arr):
        if arr[i] != (i+1):
            t = a_map[arr[i]-1]
            a_map[arr[i]-1] = arr[i]
            arr[i] = t
            swaps += 1
        else:
            i += 1
    return swaps