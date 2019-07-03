// Complete the sockMerchant function below.
func sockMerchant(n: Int, ar: [Int]) -> Int {
    var ar_cpy = ar
    ar_cpy.sort()
    var it = 0
    var sockPairs = 0
    while it < (n-1) {
        if ar_cpy[it] == ar_cpy[it+1] {
            sockPairs += 1
            it += 2
        } else {
            it += 1
        }
    }
    return sockPairs
}