
def get_cost(mb, mi):
    cost = 0
    for i in range(0, 3):
        for j in range(0, 3):
            cost += abs(mb[i][j]-mi[i][j])
    return cost

# Complete the formingMagicSquare function below.
def formingMagicSquare(s):
    mset = {1: [[2, 9, 4], [7, 5, 3], [6, 1, 8]],
        2: [[2,7,6], [9,5,1], [4,3,8]],
        3: [[6,1,8], [7,5,3], [2,9,4]],
        4: [[8,3,4], [1,5,9], [6,7,2]],
        5: [[4,9,2], [3,5,7], [8,1,6]],
        6: [[4,3,8], [9,5,1], [2,7,6]],
        7: [[8,1,6], [3,5,7], [4,9,2]],
        8: [[6,7,2], [1,5,9], [8,3,4]]}
    costs = []
    for i in range(1, 9):
        costs.append(get_cost(mset[i], s))
    costs.sort()
    return costs[0]