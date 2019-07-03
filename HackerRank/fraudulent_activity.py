# Complete the activityNotifications function below.
def activityNotifications(expenditure, d):
    it = 0
    oq = [0]*(201)
    for i in range(0, len(expenditure[:d])):
        oq[expenditure[i]] += 1
    nfs = 0
    while (it+d) < len(expenditure):
        m = get_median(oq[:], d)
        if expenditure[it+d] >= 2*m:
            nfs += 1
        oq[expenditure[it+d]] += 1
        oq[expenditure[it]] -= 1
        it += 1
    return nfs