// Complete the diagonalDifference function below.
func diagonalDifference(arr: [[Int]]) -> Int {
    var leftDiag = 0
    var rightDiag = 0
    let size = arr[0].count
    for v in 0..<size {
        leftDiag += arr[v][v]
        rightDiag += arr[v][(size-v)-1]
    }
    return abs(leftDiag - rightDiag)
}