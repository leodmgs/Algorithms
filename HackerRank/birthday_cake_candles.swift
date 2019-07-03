// Complete the birthdayCakeCandles function below.
func birthdayCakeCandles(ar: [Int]) -> Int {
    var ar_cpy = ar
    ar_cpy.sort()
    var counter = 1
    let taller = ar_cpy[ar_cpy.count-1]
    for i in (0..<ar_cpy.count-1).reversed() {
        if ar_cpy[i] == taller {
            counter += 1
        }
    }
    return counter
}