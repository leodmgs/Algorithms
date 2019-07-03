# Complete the maximumToys function below.
def maximumToys(prices, k):
    t = 0
    s = 0
    prices.sort()
    for tp in prices:
        if (tp + s) > k: break
        s += tp
        t += 1
    return t