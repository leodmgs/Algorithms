// Complete the compareTriplets function below.
func compareTriplets(a: [Int], b: [Int]) -> [Int] {
    var r: [Int] = [0, 0]
    for i in 0..<a.count {
        if a[i] < b[i] {
            r[1] += 1
        } else if a[i] > b[i] {
            r[0] += 1
        }
    }
    return r
}