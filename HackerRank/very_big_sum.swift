// Complete the aVeryBigSum function below.
func aVeryBigSum(ar: [Int]) -> Int {
    return ar.reduce(0, { $0 + $1 })
}