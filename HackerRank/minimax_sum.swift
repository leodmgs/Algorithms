// Complete the miniMaxSum function below.
func miniMaxSum(arr: [Int]) -> Void {
    var arrAux = arr
    arrAux.sort()
    let min = arrAux[0..<arrAux.count - 1].reduce(0, +)
    let max = arrAux[1..<arrAux.count].reduce(0, +)
    print("\(min) \(max)")
}